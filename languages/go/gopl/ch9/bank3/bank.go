package bank

import (
	"sync"
)

var (
	mu      sync.Mutex // guards balance
	balance int
)

func Deposit(amount int) {
	mu.Lock()
	balance = balance + amount
	mu.Unlock()
}

func Balance() int {
	mu.Lock()
	defer mu.Unlock() // unlock after return statement
	return balance    // nolonger need local variable
}
