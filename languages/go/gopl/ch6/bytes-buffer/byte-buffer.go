package bytesbuffer

type Buffer struct {
	buf     []byte
	initial [64]byte
	/* ... */
}

// Grow expands the buffer's capacity, if necessary,
// to guarantee space for another n bytes. [...]
func (b *Buffer) Grow(n int) {
	if b.buf == nil {
		b.buf = b.initial[:0] // use preallocated space initially
	}
	if len(b.buf)+n > cap(b.buf) {
		buf := make([]byte, 2*cap(b.buf)+n)
		copy(buf, b.buf)
		b.buf = buf
	}
}
