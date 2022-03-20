package main

import (
	"bytes"
	"fmt"
)

type IntSet struct {
	words []uint64
}

// Has reports whether the set contains the non-negative value x.
func (s *IntSet) Has(x int) bool {
	word, bit := x/64, uint(x%64)
	return word < len(s.words) && s.words[word]&(1<<bit) != 0
}

// Add adds the non-negative value x to the set.
func (s *IntSet) Add(x int) {
	word, bit := x/64, uint(x%64)
	for word >= len(s.words) {
		s.words = append(s.words, 0)
	}
	s.words[word] |= 1 << bit
}

func (s *IntSet) UnionWith(t *IntSet) {
	for i, tword := range t.words {
		if i < len(s.words) {
			s.words[i] |= tword
		} else {
			s.words = append(s.words, tword)
		}
	}
}

func (s *IntSet) String() string {
	var buf bytes.Buffer
	buf.WriteByte('{')
	for i, word := range s.words {
		if word == 0 {
			continue
		}
		for j := 0; j < 64; j++ {
			if word&(1<<uint(j)) != 0 {
				if buf.Len() > len("{") {
					buf.WriteByte(' ')
				}
				fmt.Fprintf(&buf, "%d", i*64+j)
			}
		}
	}
	buf.WriteByte('}')
	return buf.String()
}

// func (s *IntSet) String() string {
// 	var sb strings.Builder
// 	sb.WriteString("{")
// 	for i, word := range s.words {
// 		if word == 0 {
// 			continue
// 		}
// 		for j := 0; j < 64; j++ {
// 			if word&(1<<uint(j)) != 0 {
// 				if sb.Len() > len("{") {
// 					sb.WriteString(" ")
// 				}
// 				fmt.Fprintf(&sb, "%d", i*64+j)
// 				// sb.WriteString(fmt.Sprintf("%d", i*64+j))
// 			}
// 		}
// 	}
// 	sb.WriteString("}")
// 	return sb.String()
// }

func main() {
	var x, y IntSet

	x.Add(1)
	x.Add(144)
	x.Add(9)
	fmt.Println(x.String()) // "{1 9 144}"

	y.Add(9)
	y.Add(42)
	fmt.Println(y.String()) // "{9 42}"

	x.UnionWith(&y)
	fmt.Println(x.String())           // "{1 9 42 144}"
	fmt.Println(x.Has(9), x.Has(123)) // "true false"
}
