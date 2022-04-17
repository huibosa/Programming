package codemotion

import "testing"

var (
	nums1 = make([]float64, 20000)
	nums2 = make([]float64, 10000)
	n     = int64(100)
	// k     = int64(100)
)

func BenchmarkOriginal(b *testing.B) {
	for i := 0; i < b.N; i++ {
		setRowOri(nums1, nums2, n)
	}
}

func BenchmarkCodeMotion(b *testing.B) {
	for i := 0; i < b.N; i++ {
		setRowReduntionInStrength(nums1, nums2, n)
	}
}
