// The expression x&(x-1) clears the rig htmost non-zero bit of x. Write a version
// of PopCount that counts bits by using this fac t, and ass ess its per for
// mance.
package popcount

var pc [256]byte

func init() {
	for i := range pc {
		pc[i] = pc[i/2] + byte(i&1)
	}
}

func PopCount(x uint64) int {
}
