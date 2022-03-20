package main

import "sync"

var (
	mu      sync.Mutex // guards map
	mapping = make(map[string]string)
)

func Lookup(key string) string {
	mu.Lock()
	v := mapping[key]
	mu.Unlock()
	return v
}
