package main

import (
	"fmt"
	"gopl/ch5/html"
	"io"
)

type StringReader string

func (sr *StringReader) Read(p []byte) (n int, err error) {
	copy(p, []byte(*sr))
	n = len(*sr)
	err = io.EOF
	return
}

func NewStringReader(s string) *StringReader {
	var sr = StringReader(s)
	return &sr
}

func main() {
	doc, _ := html.Parse(NewStringReader("<html><body><h1>hello</h1></body></html>"))
	fmt.Println(doc)
}
