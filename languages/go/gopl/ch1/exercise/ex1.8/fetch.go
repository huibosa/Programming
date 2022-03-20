package main

// Modify fetch to add the prefix http:// to each argument URL if it is missing.
// You might want to use strings.HasPrefix.

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"os"
	"strings"
)

func main() {
	for _, url := range os.Args[1:] {
		if !strings.HasPrefix(url, "http://") {
			url = "http://" + url
		}
		resp, err := http.Get(url)
		check(err)

		b, err := ioutil.ReadAll(resp.Body)
		resp.Body.Close()
		check(err)
		fmt.Printf("%s", b)
	}
}

func check(e error) {
	if e != nil {
		fmt.Fprintf(os.Stderr, "fetch: %v\n", e)
		os.Exit(1)
	}
}
