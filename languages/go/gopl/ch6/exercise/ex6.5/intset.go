package main

import (
	"log"
	"strconv"
	"strings"
)

const SizeOfUint = 32 << (^uint(0) >> 63)

type IntSet struct {
	words []uint
}

func (s *IntSet) Has(x int) bool {
	w, b := x/64, uint(x%64)
	return w < len(s.words) && s.words[w]&(1<<b) != 0
}

func (s *IntSet) Add(x int) {
	w, b := x/64, uint(x%64)
	for w >= len(s.words) {
		s.words = append(s.words, 0)
	}
	s.words[w] |= (1 << b)
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

func (s *IntSet) IntersectWith(t *IntSet) {
	if len(s.words) > len(t.words) {
		s, t = t, s // make s point to shorter set
	}
	for i := range s.words {
		s.words[i] &= t.words[i]
	}
}

func (s *IntSet) DifferenceWith(t *IntSet) {
	if len(s.words) > len(t.words) {
		s, t = t, s // make s point to shorter set
	}
	for i := range s.words {
		s.words[i] &= ^t.words[i]
	}
}

func (s *IntSet) SymmetricDifferencWith(t *IntSet) {
	sOri := s.Copy()
	s.DifferenceWith(t)
	t.DifferenceWith(sOri)
	s.UnionWith(t)
}

func (s *IntSet) Len() (length int) {
	for _, word := range s.words {
		if word == 0 {
			continue
		}
		for i := 0; i < 64; i++ {
			if word&(1<<i) != 0 {
				length++
			}
		}
	}
	return
}

func (s *IntSet) Remove(x int) {
	w, b := x/64, uint(x%64)
	if w > len(s.words) {
		log.Print("No such entry")
	}
	s.words[w] &= ^(1 << b) // turn off bit
}

func (s *IntSet) Clear() {
	s.words = []uint{}
}

func (s *IntSet) Copy() *IntSet {
	ret := new(IntSet)
	ret.words = make([]uint, len(s.words))
	copy(ret.words, s.words)
	return ret
}

func (s *IntSet) String() string {
	var sb strings.Builder
	sb.WriteString("{")
	for i, word := range s.words {
		if word == 0 {
			continue
		}
		for j := 0; j < 64; j++ {
			if word&(1<<j) != 0 {
				if sb.Len() > 1 {
					sb.WriteString(" ")
				}
				sb.WriteString(strconv.Itoa(i*64 + j))
			}
		}
	}
	sb.WriteString("}")
	return sb.String()
}

func (s *IntSet) AddAll(vals ...int) {
	for _, v := range vals {
		if !s.Has(v) {
			s.Add(v)
		}
	}
}

func (s *IntSet) Elems() []int {
	var ret []int
	for i, word := range s.words {
		if word == 0 {
			continue
		}
		for j := 0; j < 64; j++ {
			if word&(1<<j) != 0 {
				ret = append(ret, i*64+j)
			}
		}
	}
	return ret
}

func sizeOfInt() int {
	i := 0
	for u := ^uint(0); u != 0; u >>= 1 {
		i++
	}
	return i
}
