package memo

import "sync"

var mu sync.Mutex

// A Memo caches the results of calling a Func.
type Memo struct {
	f     Func
	mu    sync.Mutex // guards cache
	cache map[string]result
}

// Func is the type of the function to memoize.
type Func func(key string) (any, error)
type result struct {
	value any
	err   error
}

func New(f Func) *Memo {
	return &Memo{
		f:     f,
		cache: make(map[string]result),
	}
}

// some URLs are being fetched twice which
// happens when two or more goroutines
// call Get for the same URL at about the same time
func (memo *Memo) Get(key string) (any, error) {
	memo.mu.Lock()
	res, ok := memo.cache[key]
	memo.mu.Unlock()
	if !ok {
		res.value, res.err = memo.f(key)

		// Between the two critical sections, several goroutines
		// may race to compute f(key) and update the map.
		memo.mu.Lock()
		memo.cache[key] = res
		memo.mu.Unlock()
	}
	return res.value, res.err
}
