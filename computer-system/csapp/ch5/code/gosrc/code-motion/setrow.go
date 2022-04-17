package codemotion

func setRowOri(a []float64, b []float64, i int64, n int64) {
	for j := int64(0); j < n; j++ {
		a[n*i+j] = b[j]
	}
}

func setRowCodeMotion(a []float64, b []float64, i int64, n int64) {
	ni := n * i
	for j := int64(0); j < n; j++ {
		a[ni+j] = b[j]
	}
}
