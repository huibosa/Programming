package main

import "fmt"

type Currency int

const (
	USD Currency = iota
	EUR
	GBP
	RMB
)

func main() {
	symbol := [...]string{USD: "$", EUR: "₵", GBP: "!", RMB: "¥"}
	fmt.Println(RMB, symbol[RMB]) // "3 ¥"

	// defines an array r with 100 elements, all zero except for the last, which has value −1.
	// r := [...]int{99: -1}
}
