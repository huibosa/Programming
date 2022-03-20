package main

func main() {
	i := 3
	a := []int{0, 1, 2, 3, 4, 5, 6, 7, 8}
	a = append(a[:i], a[i+1:]...)

	a = []int{0, 1, 2, 3, 4, 5, 6, 7, 8}
	copy(a[i:], a[i+1:])
}
