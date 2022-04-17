package main

import (
	"log"
	"os"
)

func main() {
	var final []byte
	for _, filename := range os.Args[1:] {
		single, err := os.ReadFile(filename)
		if err != nil {
			log.Fatal(err)
		}
		final = append(final, single...)
	}
	os.Stdout.Write(final)
}
