// Exercise 1.4: Modify dup2 to print the names of all files in which each duplicated line occurs.

package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
)

func main() {
	counts := make(map[string]int)
	foundIn := make(map[string][]string)
	fnames := os.Args[1:]

	if len(fnames) == 0 {
		countLines(os.Stdin, counts, foundIn)
	} else {
		for _, fname := range fnames {
			f, err := os.Open(fname)
			if err != nil {
				log.Fatal(err)
			}
			defer f.Close()

			countLines(f, counts, foundIn)
		}
		for str, files := range foundIn {
			if len(files) > 0 {
				fmt.Printf("%s: %v", str, files)
			}
		}
	}
}

func in(needle string, strs []string) bool {
	for _, s := range strs {
		if needle == s {
			return true
		}
	}
	return false
}

func countLines(f *os.File, counts map[string]int, foundIn map[string][]string) {
	input := bufio.NewScanner(f)
	for input.Scan() {
		str := input.Text()
		counts[str]++
		if !in(f.Name(), foundIn[str]) {
			foundIn[str] = append(foundIn[str], f.Name())
		}
	}
}
