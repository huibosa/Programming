// insert n element at position i
package main

func main() {
	s := make([]int, 10)
	i := 5

	s = append(s[:i], append(make([]int, 3), s[i:]...)...)
}
