package main

import (
	"io"
	"os"
)

func main() {
	os.Stdout.Write([]byte("hello")) // OK: *os.File has Write method
	os.Stdout.Close()                // OK: *os.File has Close method
	var w io.Writer
	w = os.Stdout
	w.Write([]byte("hello")) // OK: io.Writer has Write method
	w.Close()                // compile error: io.Writer lacks Close method
}
