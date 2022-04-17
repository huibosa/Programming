package main

import "fmt"

func CutWithGC(s []int, i, j int) []int {
	copy(s[i:], s[j:])

	for p, q := len(s)-j+i, len(s); p < q; p++ {
		s[p] = 0
	}

	return s[:len(s)-j+i]
}

func CutWithoutGC(s []int, i, j int) []int {
	return append(s[:i], s[j:]...)
}

func main() {
	a := []int{1, 2, 3, 4, 5, 6, 7}
	a = CutWithGC(a, 2, 4)
	fmt.Println(a)

	a = []int{1, 2, 3, 4, 5, 6, 7}
	a = CutWithoutGC(a, 2, 4)
	fmt.Println(a)
}
