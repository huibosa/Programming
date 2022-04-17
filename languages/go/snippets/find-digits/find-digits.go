package funcs

import (
	"os"
	"regexp"
)

var digitRegexp = regexp.MustCompile("[0-9]+")

func FindDigits(fname string) []byte {
	b, _ := os.ReadFile(fname)
	return digitRegexp.Find(b)
}
