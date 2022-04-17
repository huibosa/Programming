package main

import (
	"fmt"
)

func main() {
	ch := make(chan int)
	done := make(chan bool)
	var bag1 []int
	var bag2 []int
	var bag3 []int

	go func() {
		for i := 0; i < 1000000; i++ {
			ch <- i
		}
		close(ch)
		done <- true
	}()

	go sendToBag(&bag1, ch)
	go sendToBag(&bag2, ch)
	go sendToBag(&bag3, ch)

	<-done

	len1 := (len(bag1))
	len2 := (len(bag2))
	len3 := (len(bag3))

	fmt.Println("length of bag1:", len1)
	fmt.Println("length of bag2:", len2)
	fmt.Println("length of bag3:", len3)
	fmt.Println("total length:", len1+len2+len3)
}

func sendToBag(bag *[]int, ch <-chan int) {
	for n := range ch {
		*bag = append(*bag, n)
	}
}
