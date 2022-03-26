package counter

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
