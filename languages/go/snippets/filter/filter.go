package funcs

func Filter(s []int, fn func(int) bool) []int {
	var ret []int // == nil

	for _, v := range s {
		if fn(v) {
			ret = append(ret, v)
		}
	}

	return ret
}
