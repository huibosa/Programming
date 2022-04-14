package procedurecalls

import (
	"math/rand"
	"testing"
)

const size = 10

var bts []byte = make([]byte, size)

func init() {
	rand.Read(bts)
}

func BenchmarkLower1(b *testing.B) {
	for i := 0; i < b.N; i++ {
		lower1(string(bts))
	}
}

func BenchmarkLower2(b *testing.B) {
	for i := 0; i < b.N; i++ {
		lower2(string(bts))
	}
}
