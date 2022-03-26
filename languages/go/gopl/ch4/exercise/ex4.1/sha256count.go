package main

import (
	"crypto/sha256"
	"fmt"
)

var pc [256]byte

func CountDiff(c1, c2 [32]byte) int {
	count := 0
	for i := range c1 {
		count += countDiffByte(c1[i], c2[i])
	}
	return count
}

func countDiffByte(b1, b2 byte) int {
	count := 0
	for i := uint(0); i < 8; i++ {
		bit1 := (b1 >> i) & 0x1
		bit2 := (b2 >> i) & 0x1
		if bit1 == bit2 {
			count++
		}
	}
	return count
}

func main() {
	c1 := sha256.Sum256([]byte("x"))
	c2 := sha256.Sum256([]byte("X"))

	fmt.Println(CountDiff(c1, c2))
}
