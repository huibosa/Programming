package main

import "fmt"

func main() {
	var i any
	describe(i)

	i = 42
	describe(i)

	i = "hello"
	describe(i)
}

func describe(x any) {
	fmt.Printf("(%v, %T)\n", x, x)
}
