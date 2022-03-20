package main

import (
	"fmt"
	"io"
	"net/http"
	"net/url"
	"os"
	"time"
)

func main() {
	start := time.Now()
	ch := make(chan string)

	for _, url := range os.Args[1:] {
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

	f, err := os.Create(url.QueryEscape(uri)) // create output file
	if err != nil {
		ch <- fmt.Sprint(err)
		return
	}

	nbytes, err := io.Copy(f, resp.Body) // write to file
	resp.Body.Close()
	if err != nil {
		ch <- fmt.Sprintf("while reading %s: %v", uri, err)
		return
	}

	secs := time.Since(start).Seconds()
	ch <- fmt.Sprintf("%.2f  %7d  %s", secs, nbytes, uri) // print time
}
