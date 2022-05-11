package main

import (
	"fmt"
	"strconv"
)

func intToBinary(n int) string {
	var ret string
	for ; n != 0; n >>= 1 {
		ret = strconv.Itoa(n&0x1) + ret
	}
	return ret
}

func main() {
	fmt.Println(intToBinary(10))
}
