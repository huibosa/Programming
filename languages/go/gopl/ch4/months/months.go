package main

import "fmt"

func main() {
	months := [...]string{
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December",
	}
	Q2 := months[4:7]
	summer := months[6:9]
	fmt.Println(Q2)     // ["April" "May", "June"]
	fmt.Println(summer) // ["June", "July", "August"]

	for _, s := range summer {
		for _, q := range Q2 {
			if s == q {
				fmt.Printf("%s is in both\n", s)
			}
		}
	}

	fmt.Println(summer[:20])    // panic: out of range
	endlessSummer := summer[:5] // extend a slice (within capacity)
	fmt.Println(endlessSummer)
}
