package codemotion

func setRowOri(a []float64, b []float64, n int64) {
	for i := int64(0); i < n; i++ {
		ni := n * i
		for j := int64(0); j < n; j++ {
			a[ni+j] = b[j]
		}
	}
}

func setRowReduntionInStrength(a []float64, b []float64, n int64) {
	ni := int64(0)
	for i := int64(0); i < n; i++ {
		for j := int64(0); j < n; j++ {
			a[ni+j] = b[j]
		}
		ni += n
	}
}
