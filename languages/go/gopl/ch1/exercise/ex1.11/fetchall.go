package main

import (
	"fmt"
	"io"
	"net/http"
	"os"
	"strings"
	"time"
)

func main() {
	start := time.Now()
	ch := make(chan string)

	for _, url := range os.Args[1:] {
		addPrefix(&url, "http://")
		go fetch(url, ch)
	}

	for range os.Args[1:] {
		fmt.Println(<-ch)
	}

	fmt.Printf("%.2f elapsed\n", time.Since(start).Seconds())
}

func fetch(uri string, ch chan string) {
	start := time.Now()

	resp, err := http.Get(uri)
	if err != nil {
		ch <- fmt.Sprint(err)
		return
	}

	nbytes, err := io.Copy(io.Discard, resp.Body)
	resp.Body.Close()
	if err != nil {
		ch <- fmt.Sprintf("while reading %s: %v", uri, err)
		return
	}

	secs := time.Since(start).Seconds()
	ch <- fmt.Sprintf("%.2f  %7d  %s", secs, nbytes, uri)
}

func addPrefix(s *string, pre string) {
	if !strings.HasPrefix(*s, pre) {
		*s = pre + *s
	}
}
