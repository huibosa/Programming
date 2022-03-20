package main

import (
	"io"
	"time"
)

// Album
// Book
// Movie
// Magazine
// Podcast
// TVEpisode
// Track

type Artifact interface {
	Title() string
	Creators() string
	Created() time.Time
}

type Text interface {
	Pages() int
	Words() int
	PageSize() int
}

type Audio interface {
	Stream() (io.ReadCloser, error)
	RunningTime() time.Duration
	Format() string // e.g, "MP3", "WAV"
}

type Video interface {
	Stream() (io.ReadCloser, error)
	RunningTime() time.Duration
	Format() string // e.g, "MP3", "WAV"
	Resolution() (x, y int)
}

type Streamer interface {
	Stream() (io.ReadCloser, error)
	RunningTime() time.Duration
	Format() string
}
