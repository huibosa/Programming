package main

import (
	"fmt"
	"net/http"
)

func main() {
	http.HandleFunc("/", handler)
	http.ListenAndServe(":8080", nil)
}

func handler(writer http.ResponseWriter, response *http.Request) {
	fmt.Fprintf(writer, "Hello, World, %s", response.URL.Path[1:])
}
