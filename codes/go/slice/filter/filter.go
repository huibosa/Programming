package main

func Filter(s []int, keep func(int) bool) []int {
	n := 0
	for _, v := range s {
		if keep(v) {
			s[n] = v
			n++
		}
	}
	return s[:n]
}
