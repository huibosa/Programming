package main

func DeleteWithoutGC(s []int, i int) []int {
	s[i] = s[len(s)-1]
	return s[:len(s)-1]
}

func DeleteWithGC(s []int, i int) []int {
	s[i] = s[len(s)-1]
	s[len(s)-1] = 0 // set last to nil
	return s[:len(s)-1]
}
