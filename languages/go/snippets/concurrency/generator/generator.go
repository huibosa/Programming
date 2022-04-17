package main

import (
	"fmt"
)

func main() {
	nums := make([]int, 100)
	for i := 0; i < 100; i++ {
		nums[i] = i
	}

	out := sq(gen(nums...))

	fmt.Println(<-out)
	fmt.Println(<-out)
	fmt.Println(<-out)
	fmt.Println(<-out)
	// main return before close() in both functions was called
}

func gen(nums ...int) chan int {
	out := make(chan int)
	go func() {
		for _, n := range nums {
			out <- n
		}
		close(out)
	}()
	return out
}

func sq(in <-chan int) chan int {
	out := make(chan int)
	go func() {
		for v := range in {
			out <- v * v
		}
		close(out)
	}()
	return out
}
