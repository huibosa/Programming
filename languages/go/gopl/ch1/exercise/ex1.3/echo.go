// Exercise 1.1: Modify the echo program to also print os.Args[0], the name of the command
// that invoked it.

package main

import (
	"fmt"
	"os"
	"strings"
	"time"
)

func main() {
	cnt := 1000

	t1 := time.Now()
	for i := 0; i < cnt; i++ {
		printArgs1()
	}
	fmt.Println(time.Since(t1).Nanoseconds() / int64(cnt))

	t2 := time.Now()
	for i := 0; i < cnt; i++ {
		printArgs2()
	}
	fmt.Println(time.Since(t2).Nanoseconds() / int64(cnt))
}

func printArgs1() {
	fmt.Println(strings.Join(os.Args[1:], " "))
}

func printArgs2() {
	s, sep := "", " "
	for _, args := range os.Args[1:] {
		s += args + sep
	}
	fmt.Println(s)
}
