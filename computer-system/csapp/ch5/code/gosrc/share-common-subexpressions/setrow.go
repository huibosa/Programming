package sharecommonsubexpressions

func SumSubMat(mat []float64, n int64) float64 {
	var (
		up    float64
		down  float64
		left  float64
		right float64
	)
	sum := 0.0

	for i := int64(1); i < n-1; i++ {
		for j := int64(1); j < n-1; j++ {
			up = mat[(i-1)*n+j]
			down = mat[(i+1)*n+j]
			left = mat[n*i+j-1]
			right = mat[n*i+j+1]
			sum += up + down + left + right
		}
	}
	return sum
}

func SumSubMatShareExpr(mat []float64, n int64) float64 {
	var (
		up    float64
		down  float64
		left  float64
		right float64
	)
	sum := 0.0
	for i := int64(1); i < n-1; i++ {
		for j := int64(1); j < n-1; j++ {
			inj := i*n + j
			up = mat[inj-n]
			down = mat[inj+n]
			left = mat[inj-1]
			right = mat[inj+1]
			sum += up + down + left + right
		}
	}
	return sum
}
