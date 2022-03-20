package main

import (
	"fmt"
	"log"
	"net/http"
	"os"
	"strings"
	"sync"
)

func main() {
	var wg = &sync.WaitGroup{}
	responses := make(chan *http.Response)
	cancel := make(chan struct{})

	for _, url := range os.Args[1:] {
		wg.Add(1)
		go func(url string) {
			defer wg.Done()

			req, err := http.NewRequest("HEAD", url, nil)
			if err != nil {
				log.Printf("HEAD %s: %s", url, err)
				return
			}

			req.Cancel = cancel // WARNING: Cancel is deprecated

			resp, err := http.DefaultClient.Do(req)
			if err != nil {
				log.Printf("HEAD %s: %s", url, err)
				return
			}
			responses <- resp
		}(url)
	}

	resp := <-responses
	defer resp.Body.Close()

	close(cancel) // cancel incomplete request

	fmt.Println(resp.Request.URL)
	for name, vals := range resp.Header {
		fmt.Printf("%s: %s\n", name, strings.Join(vals, ","))
	}

	wg.Wait()
}
