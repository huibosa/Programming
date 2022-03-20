// Exercise 1.1: Modify the echo program to also print os.Args[0], the name of the command
// that invoked it.

package main

import (
	"fmt"
	"os"
)

func main() {
	s, sep := "", ""
	for _, arg := range os.Args[:] {
		s += sep + arg
		sep = " "
	}
	fmt.Println(s)
}
