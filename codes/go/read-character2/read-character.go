package main

import (
	"fmt"
	"log"
)

func main() {
	fmt.Println("input text:")
	var char rune
	_, err := fmt.Scanf("%c", &char)
	if err != nil {
		log.Fatal(err)
	}

	fmt.Printf("read character: %c-\n", char)
}
