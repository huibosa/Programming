package main

import (
	"fmt"
	"log"
)

func main() {
	fmt.Println("input text:")
	var name string
	var country string
	n, err := fmt.Scanf("%s is born in %s", &name, &country)
	if err != nil {
		log.Fatal(err)
	}

	fmt.Printf("number of items read: %d\n", n)
	fmt.Println(name, country)
}
