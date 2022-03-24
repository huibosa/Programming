package main

import "fmt"

type Number interface {
	int8 | int64 | float64
}

type CustomSlice[T Number] []T

func Print[N Number, T CustomSlice[N]](s T) {
	for _, v := range s {
		fmt.Println(v)
	}
}

func main() {
	sl := CustomSlice[int64]{32, 32, 32}
	Print(sl)
}
