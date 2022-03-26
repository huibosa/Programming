package reverse

import (
	"fmt"
	"testing"
)

func TestRotate(t *testing.T) {
	s := []int{0, 1, 2, 3, 4, 5}
	// Rotate s left by two positions
	reverse(s[:2])
	reverse(s[2:])
	reverse(s)

	want := "[2 3 4 5 0 1]"
	got := fmt.Sprint(s)
	if got != want {
		t.Errorf("Rotate(x) = %s, want: %s", got, want)
	}
}
