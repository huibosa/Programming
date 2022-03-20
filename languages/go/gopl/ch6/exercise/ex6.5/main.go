package main

import "fmt"

func main() {
	set1 := new(IntSet)
	set2 := new(IntSet)

	set1.AddAll(1, 2, 3, 5)
	set2.AddAll(2, 4, 6)
	set1.SymmetricDifferencWith(set2)

	fmt.Println(set1.Elems())
}
