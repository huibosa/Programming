package counter

import "testing"

func TestLineCounter(t *testing.T) {
	tests := []struct {
		text string
		want int
	}{
		{"abc\ncdc\ndd\n", 3},
		{"", 0},
		{"\n", 1},
		{"cc\n", 1},
		{"aa", 1},
		{"\n\n", 2},
		{"a\n\n", 2},
	}

	for _, test := range tests {
		c := new(LineCounter)
		if _, err := c.Write([]byte(test.text)); err != nil {
			t.Errorf("%s", err)
		}
		if int(*c) != test.want {
			t.Errorf("LineCouter(%q) = %v, want %v", test.text, *c, test.want)
		}
	}
}

func TestWordCounter(t *testing.T) {
	tests := []struct {
		text string
		want int
	}{
		{"ab cd ee", 3},
		{"", 0},
		{"\n", 0},
		{"cc\n", 1},
		{"aa", 1},
		{"\n\n", 0},
		{"a\n\n", 1},
	}

	for _, test := range tests {
		c := new(WordCounter)
		if _, err := c.Write([]byte(test.text)); err != nil {
			t.Errorf("%s", err)
		}
		if int(*c) != test.want {
			t.Errorf("WordCouter(%q) = %v, want %v", test.text, *c, test.want)
		}
	}
}
