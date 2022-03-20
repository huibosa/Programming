// Exercise 8.9: Write a version of du that computes and periodically
// displays separate totals for each of the root directories
package main

import (
	"flag"
	"fmt"
	"io/ioutil"
	"log"
	"os"
	"path/filepath"
	"sync"
	"time"
)

var verbose = flag.Bool("v", false, "show verbose progress messages")

type fileInfo struct {
	root string
	size int64
}

func main() {
	flag.Parse()
	roots := flag.Args()
	if len(roots) == 0 {
		roots = []string{"."}
	}

	fileInfos := make(chan fileInfo)
	var n sync.WaitGroup
	for _, root := range roots {
		n.Add(1)
		go walkDir(root, &n, fileInfos)
	}

	go func() {
		n.Wait()
		close(fileInfos)
	}()

	var tick <-chan time.Time
	if *verbose {
		tick = time.Tick(500 * time.Millisecond)
	}

	numMap := make(map[string]int64)
	sizeMap := make(map[string]int64)
loop:
	for {
		select {
		case info, ok := <-fileInfos:
			if !ok {
				break loop
			}
			sizeMap[info.root] += info.size
			numMap[info.root]++
		case <-tick:
			printDiskUsage(numMap, sizeMap)
		}
	}
	printDiskUsage(numMap, sizeMap)
}

func printDiskUsage(numMap, sizeMap map[string]int64) {
	for k := range numMap {
		fmt.Printf("%10d files  %.3f GB under %s\n", numMap[k], float64(sizeMap[k])/1e9, k)
	}

}

func walkDir(dir string, n *sync.WaitGroup, fileSizes chan<- fileInfo) {
	defer n.Done()
	for _, entry := range dirents(dir) {
		if entry.IsDir() {
			n.Add(1)
			subdir := filepath.Join(dir, entry.Name())
			go walkDir(subdir, n, fileSizes)
		} else {
			fileSizes <- fileInfo{dir, entry.Size()}
		}
	}
}

var sema = make(chan struct{}, 20)

func dirents(dir string) []os.FileInfo {
	sema <- struct{}{}
	defer func() { <-sema }()
	entries, err := ioutil.ReadDir(dir)
	if err != nil {
		log.Fatal(err)
	}
	return entries
}
