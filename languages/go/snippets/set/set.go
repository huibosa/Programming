package main

import "fmt"

func main() {
	s := map[int]bool{5: true, 2: true}

	if s[6] {
		fmt.Println("exist")
	} // check for existence
	s[8] = true  // add element
	delete(s, 2) // remove element
}

func union(s1, s2 map[int]bool) map[int]bool {
	ret := make(map[int]bool)

	for k := range s1 {
		ret[k] = true
	}

	for k := range s2 {
		ret[k] = true
	}

	return ret
}

func intersect(s1, s2 map[int]bool) map[int]bool {
	ret := make(map[int]bool)

	// iterate shorter set
	if len(s2) < len(s1) {
		s1, s2 = s2, s1
	}

	for k := range s1 {
		if s2[k] {
			ret[k] = true
		}
	}
	return ret
}
