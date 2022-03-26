package main

import (
	"fmt"
	"gopl/ch5/html"
	"io"
)

type StringReader struct {
	str string
	i   int
}

func (sr *StringReader) Read(p []byte) (n int, err error) {
	if sr.i >= len(sr.str) {
		return 0, io.EOF
	}
	n = copy(p, []byte(sr.str[sr.i:]))
	sr.i += n
	return
}

func NewStringReader(s string) *StringReader {
	var sr = StringReader{
		str: s,
		i:   0,
	}
	return &sr
}

func main() {
	doc, _ := html.Parse(NewStringReader("<html><body><h1>hello</h1></body></html>"))
	fmt.Println(doc)
}
