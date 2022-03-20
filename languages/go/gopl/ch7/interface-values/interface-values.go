package main

import (
	"bytes"
	"io"
	"os"
)

func main() {
	var w io.Writer
	w.Write([]byte("hello")) // panic: nil pointer dereference

	w = os.Stdout            // w = io.Writer(os.Stdout)
	w.Write([]byte("hello")) // os.Stdout.Write([]byte("hello"))

	w = new(bytes.Buffer)
	w.Write([]byte("hello"))

	w = nil
}
