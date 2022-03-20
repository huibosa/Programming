// Exercise 2.4: Write a version of PopCount that counts bits by shifting
// its argument through 64 bit positions, testing the rightmost bit each
// time. Compare its per formance to the table-lookup version.
package popcount

var pc [256]byte

func init() {
	for i := range pc {
		pc[i] = pc[i/2] + byte(i&1)
	}
}

func PopCount(x uint64) int {
}
