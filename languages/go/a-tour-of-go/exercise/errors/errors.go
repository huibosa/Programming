package main

import (
	"fmt"
	"math"
)

type ErrNegativeSqrt float64

func (e ErrNegativeSqrt) Error() string {
	return fmt.Sprint("cannot Sqrt negative number:", float64(e))
}

func Sqrt(x float64) (ret float64, err error) {
	if x >= 0 {
		ret = math.Sqrt(x)
	} else {
		err = ErrNegativeSqrt(x)
	}
	return
}

func main() {
	fmt.Println(Sqrt(2))
	fmt.Println(Sqrt(-2))
}
