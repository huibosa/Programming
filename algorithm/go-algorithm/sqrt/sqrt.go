package main

import "fmt"

func Newton(x float64) float64 {
	epsilon := .0001
	g := x / 2.0

	for g*g-x >= epsilon {
		g = g - (g*g-x)/(2*g)
	}

	return g
}

func Normal(x float64) float64 {
	epsilon := .0001
	g := x / 2.0

	for g*g-x >= epsilon {
		g = (g + x/g) / 2.0
	}
	return g
}

func main() {
	x := 5.0
	fmt.Println(Newton(x))
	fmt.Println(Normal(x))
}
