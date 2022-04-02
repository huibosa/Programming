package nonempty

// nonempty returns a slice holding only the non-empty strings.
// The underlying array is modified during the call.
func nonempty(strings []string) []string {
	i := 0
	for _, s := range strings {
		if s != "" {
			strings[i] = s
			i++
		}
	}
	return strings[:i]
}

func nonempty2(strings []string) []string {
	i := 0
	for j := 0; j < len(strings); j++ {
		if strings[j] != "" {
			strings[i] = strings[j]
			i++
		}
	}
	return strings[:i]
}
