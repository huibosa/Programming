package main

func main() {
	var s []int            // len(s) == 0, s = nil
	s = nil                // len(s) == 0, s = nil
	s = []int(nil)         // len(s) == 0, s = nil
	s = []int{}            // len(s) == 0, s != nil
	s = make([]int, 0)     // len(s) == 0, s != nil
	s = make([]int, 3)[3:] // len(s) == 0, s != nil
}
