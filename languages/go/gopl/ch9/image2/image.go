package main

import (
	"image"
	"sync"
)

var (
	mu    sync.Mutex
	icons map[string]image.Image
)

func loadIcons() {
	icons = map[string]image.Image{
		"spades.png":   loadIcon("spades.png"),
		"hearts.png":   loadIcon("hearts.png"),
		"diamonds.png": loadIcon("diamonds.png"),
		"clubs.png":    loadIcon("clubs.png"),
	}
}

// Concurrency safe, but two goroutines can't read variable concurently
func Icon(name string) image.Image {
	mu.Lock()
	defer mu.Unlock()
	if icons == nil {
		loadIcons()
	}
	return icons[name]
}

func loadIcon(name string) image.Image
