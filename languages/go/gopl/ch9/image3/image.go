package main

import (
	"image"
	"sync"
)

var (
	mu    sync.RWMutex // guards icons
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

func Icon(name string) image.Image {
	mu.RLock()
	if icons != nil {
		icon := icons[name]
		mu.RUnlock()
		return icon
	}
	mu.RUnlock()

	// acquire an exclusive lock
	mu.Lock()
	if icons == nil {
		loadIcons()
	}
	icon := icons[name]
	mu.Unlock()

	return icon
}

func loadIcon(name string) image.Image
