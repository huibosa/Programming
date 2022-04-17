package main

import (
	"fmt"
	"math/rand"
	"os"
)

func main() {
	ch := make(chan struct{})

	go func() {
		for {
			os.Stdin.Read(make([]byte, 1))
			ch <- struct{}{}
		}
	}()

	for range ch {
		fmt.Println(rand.NormFloat64())
	}
}
