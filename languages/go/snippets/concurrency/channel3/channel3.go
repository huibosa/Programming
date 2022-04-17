package main

import (
	"fmt"
	"time"
)

func in(x int, ch chan int) {
	ch <- x
}

func out(p *int, ch chan int) {
	*p = <-ch
}

func main() {
	x := 13
	var p *int = &x
	var ch = make(chan int)

	go in(3, ch) // should be expecting someone to receive
	time.Sleep(4 * time.Second)
	go out(p, ch)

	fmt.Println(*p)
}
