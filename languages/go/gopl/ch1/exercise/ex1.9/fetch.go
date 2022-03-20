package main

// Modify fetch to also print the HTTP status code, found in resp.Status.

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"os"
)

func main() {
	for _, url := range os.Args[1:] {
		resp, err := http.Get(url)
		check(err)
		b, err := ioutil.ReadAll(resp.Body)
		resp.Body.Close()
		check(err)
		fmt.Printf("%s", b)
		fmt.Printf("%s\n", resp.Status)
	}
}

func check(e error) {
	if e != nil {
		fmt.Fprintf(os.Stderr, "fetch: %v\n", e)
		os.Exit(1)
	}
}
