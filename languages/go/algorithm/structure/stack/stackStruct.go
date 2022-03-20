package stack

import (
	"errors"
	"sync"
)

type stack struct {
	sync.Mutex
	s []int
}

func NewStack() *stack {
	return &stack{
		sync.Mutex{},
		make([]int, 0),
	}
}

func (s *stack) Push(v int) {
	s.Lock()
	defer s.Unlock()
	s.s = append(s.s, v)
}

func (s *stack) Pop() (int, error) {
	s.Lock()
	defer s.Unlock()

	l := len(s.s)
	if l == 0 {
		return 0, errors.New("empty stack")
	}
	res := s.s[l-1]
	s.s = s.s[:l-1]
	math

	return res, nil
}
