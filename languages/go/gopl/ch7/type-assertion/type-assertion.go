package main

import (
	"bytes"
	"io"
	"os"
)

type ByteCounter int

func (c *ByteCounter) Write(p []byte) (n int, err error) {
	*c += ByteCounter(len(p))
	return len(p), nil
}

func main() {
	var w io.Writer

	w = os.Stdout
	f := w.(*os.File)      // success: f == os.Stdout
	c := w.(*bytes.Buffer) // panics: interface holds *os.File, not *bytes.Buffer

	rw := w.(io.ReadWriter) // success: *os.File has both Read and Write

	w = new(ByteCounter)
	rw = w.(io.ReadWriter) // panic: *ByteCounter has no Read method

	w = rw             // io.ReadWriter is assignable to io.Writer
	w = rw.(io.Writer) // fails only if rw == nil

	w = os.Stdout
	f, ok := w.(*os.File)      // success: ok, f == os.Stdout
	b, ok := w.(*bytes.Buffer) // failure: !ok, b == nil

	if w, ok := w.(*os.File); ok { // reuse original name shadows original
		// ... use w...
	}
}
