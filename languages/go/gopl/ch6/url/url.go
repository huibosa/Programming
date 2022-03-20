package url

type Values map[string][]string

// Get returns the first value associate with the given key
// or "" if there are none.
func (v Values) Get(key string) string {
	if vs := v[key]; len(vs) > 0 {
		return vs[0]
	}
	return ""
}

// Add adds the value to key.
// It appends to any existing values associated with key
func (v Values) Add(key, value string) {
	v[key] = append(v[key], value)
}
