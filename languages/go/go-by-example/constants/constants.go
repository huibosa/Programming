package main

import (
	"fmt"
	"math"
)

const S string = "constant"

func main() {
	fmt.Println(S)

	const N = 5000000
	const D = 3e20 / N
	fmt.Println(D)

	fmt.Println(int64(D))

	fmt.Println(math.Sin(N))
}
