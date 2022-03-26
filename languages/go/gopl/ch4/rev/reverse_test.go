package reverse

import (
	"fmt"
	"testing"
)

func TestReverse(t *testing.T) {
	a := [...]int{0, 1, 2, 3, 4, 5}
	reverse(a[:])
	want := "[5 4 3 2 1 0]"
	got := fmt.Sprint(a)
	if got != want {
		t.Errorf("reverse(a) == %s, want %s", got, want)
	}
}
