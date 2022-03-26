package main

import "fmt"

func main() {
	var q [3]int = [3]int{1, 2, 3}
	var r [3]int = [3]int{1, 2}
	fmt.Println(r[2]) // "0"

	q := [...]int{1, 2, 3}
	fmt.Printf("%T\n", q) // "[3]int"
}
