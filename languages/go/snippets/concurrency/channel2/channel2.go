package main

import "fmt"

func calcSquares(number int, squareop chan int) {
	sum := 0
	for number != 0 {
		digit := number % 10
		sum += digit * digit
		number /= 10
	}
	squareop <- sum
}

func calcCubes(number int, cubeop chan int) {
	sum := 0
	for number != 0 {
		digit := number % 10
		sum += digit * digit * digit
		number /= 10
	}
	cubeop <- sum
}

func main() {
	num := 589
	sqCh := make(chan int)
	cbCh := make(chan int)
	go calcSquares(num, sqCh)
	go calcCubes(num, cbCh)
	squares, cubes := <-sqCh, <-cbCh
	fmt.Println(squares + cubes)
}
