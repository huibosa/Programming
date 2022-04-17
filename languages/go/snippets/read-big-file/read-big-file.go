package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strings"
)

func readBigFile(filePath string) error {
	f, err := os.Open(filePath)
	if err != nil {
		log.Fatal(err)
		return err
	}

	buf := bufio.NewReader(f)
	count := 0
	for {
		count++
		line, err := buf.ReadString('\n')
		line = strings.TrimSpace(line)
		if err != nil {
			return err
		}
		fmt.Println("line", line)

		if count > 100 {
			break
		}
	}
	return nil
}
