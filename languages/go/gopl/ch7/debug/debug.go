package main

import (
	"bytes"
	"io"
)

const debug = true

func f(out io.Writer) {
	// ...do something...
	if out != nil {
		out.Write([]byte("done!\n"))
	}
}

func main() {
	// var buf io.Writer
	var buf *bytes.Buffer
	if debug {
		buf = new(bytes.Buffer)
	}
	f(buf)
}
