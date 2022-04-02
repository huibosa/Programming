package main

import "fmt"

func facto32() {
	var prev int32
	var prod int32 = 1
	for i := int32(1); i <= 14; i++ {
		prev = prod
		prod *= i
		overflow := prev != prod/i
		fmt.Printf("prev = %10v, product(%v) = %10v, overflow: %t\n", prev, i, prod, overflow)
	}
}

func facto64() {
	var prev int64
	var prod int64 = 1
	for i := int64(1); i <= 21; i++ {
		prev = prod
		prod *= i
		overflow := prev != prod/i
		fmt.Printf("prev = %20v, product(%2v) = %20v, overflow: %t\n", prev, i, prod, overflow)
	}
}

func main() {
	facto64()
}
