package funcs

func AppendByte(slice []byte, data ...byte) []byte {
	m := len(slice)
	n := m + len(data)

	if n > cap(slice) {
		newSlice := make([]byte, (n+1)*2)
		copy(newSlice, slice)
		slice = newSlice
	}
	slice = slice[0:n]
	copy(slice[m:n], data)

	return slice
}
