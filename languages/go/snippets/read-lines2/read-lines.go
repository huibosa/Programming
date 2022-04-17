package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strings"
)

func main() {
	fmt.Println("input text:")
	reader := bufio.NewReader(os.Stdin)

	var lines []string
	for {
		line, err := (reader.ReadString('\n'))
		if err != nil {
			log.Fatal(err)
		}
		line = strings.TrimSpace(line)
		if len(line) == 0 {
			break
		}
		lines = append(lines, line)
	}

	fmt.Println("output:")
	for _, l := range lines {
		fmt.Println(l)
	}
}
