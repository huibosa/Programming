package main

import (
	"fmt"
)

func main() {
	data := "Alice is an innovative block-based programming environment that\n" +
		"makes it easy to create animations, build interactive narratives, or program\n" +
		"simple games in 3D. Unlike many of the puzzle-based coding applications Alice\n" +
		"motivates learning through creative exploration. Alice is designed to teach\n" +
		"logical and computational thinking skills, fundamental principles of\n" +
		"programming and to be a first exposure to object-oriented programming. The\n" +
		"Alice Project provides supplemental tools and materials for teaching using\n" +
		"Alice across a spectrum of ages and subject matter with proven benefits in\n" +
		"engaging and retaining diverse and underserved groups in computer science\n" +
		"education."

	wc := new(WordCounter)
	fmt.Fprint(wc, data)
	fmt.Println(*wc)

	lc := new(LineCounter)
	fmt.Fprint(lc, data)
	fmt.Println(*lc)
}
