package sharecommonsubexpressions

import "testing"

const size = 10000000

var n int64 = 1000

var mat []float64 = make([]float64, size)

func init() {
	for i := 0; i < size; i++ {
		mat[i] = float64(i)
	}
}

func BenchmarkSumOri(b *testing.B) {
	for i := 0; i < b.N; i++ {
		SumSubMat(mat, n)
	}
}

func BenchmarkSumShareExpr(b *testing.B) {
	for i := 0; i < b.N; i++ {
		SumSubMatShareExpr(mat, n)
	}
}
