package main

import (
	"bufio"
	"bytes"
)

type WordCounter int

func (c *WordCounter) Write(p []byte) (int, error) {
	buf := bytes.NewBuffer(p)
	s := bufio.NewScanner(buf)
	s.Split(bufio.ScanWords)
	for s.Scan() {
		*c++
	}
	return int(*c), nil
}
