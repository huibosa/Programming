package main

import (
	"bufio"
	"bytes"
)

type LineCounter int

func (c *LineCounter) Write(p []byte) (int, error) {
	buf := bytes.NewBuffer(p)
	s := bufio.NewScanner(buf)
	for s.Scan() {
		*c++
	}
	return int(*c), nil
}
