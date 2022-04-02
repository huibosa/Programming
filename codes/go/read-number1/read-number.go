package main

import (
	"fmt"
	"log"
)

func main() {
	fmt.Println("input number:")
	var number int64
	_, err := fmt.Scanf("%d", &number)
	if err != nil {
		log.Fatal(err)
	}

	fmt.Printf("read number: %d\n", number)
}
