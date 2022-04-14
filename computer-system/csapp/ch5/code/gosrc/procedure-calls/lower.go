package procedurecalls

import "strings"

func strlen(s string) int64 {
	var ret int64
	for i := 0; i < len(s); i++ {
		ret++
	}
	return ret
}

func lower1(s string) string {
	var b strings.Builder
	for i := int64(0); i < strlen(s); i++ {
		c := s[i]
		if c >= 'A' && c <= 'Z' {
			c -= 'a' - 'A'
		}
		b.WriteByte(c)
	}
	return b.String()
}

func lower2(s string) string {
	var b strings.Builder
	size := strlen(s)
	for i := int64(0); i < size; i++ {
		c := s[i]
		if c >= 'A' && c <= 'Z' {
			c -= 'a' - 'A'
		}
		b.WriteByte(c)
	}
	return b.String()
}
