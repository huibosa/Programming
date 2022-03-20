package main

import "fmt"

type st struct {
	val  int
	name string
}

func main() {
	ch := make(chan st)
	m := make(map[st]bool)

	st1 := st{1, "a"}

	go func() { ch <- st1 }()

	st2 := <-ch

	m[st1] = true
	m[st2] = true

	fmt.Println(m)
}
