// Exercise 2.3: Rewrite PopCount to use a loop instead of a single
// expression. Compare the performance of the two versions.
package popcount

var pc [256]byte

func init() {
	for i := range pc {
		pc[i] = pc[i/2] + byte(i&1)
	}
}

func PopCount(x uint64) int {
	var sum byte
	for i := range pc {
		sum += pc[byte(x>>(i*8))]
	}
	return int(sum)
}
