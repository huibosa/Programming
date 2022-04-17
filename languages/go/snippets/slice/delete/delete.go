package main

import "fmt"

func DeleteWithGC(s []int, i int) []int {
	copy(s[i:], s[i+1:])
	s[len(s)-1] = 0     // set last element to nil
	return s[:len(s)-1] // abandon last element
}

func DeleteWithoutGC(s []int, i int) []int {
	return append(s[:i], s[i+1:]...)
}

func main() {
	a := []int{0, 1, 2, 3, 4, 5, 6}
	a = DeleteWithGC(a, 3)
	fmt.Println(a)

	a = []int{0, 1, 2, 3, 4, 5, 6}
	a = DeleteWithoutGC(a, 3)
	fmt.Println(a)
}
