package bank

import (
	"sync"
)

var (
	mu      sync.RWMutex
	balance int
)

func Balance() int {
	mu.RLock() // readers lock
	defer mu.RUnlock()
	return balance
}

func Withdraw(amount int) bool {
	mu.Lock()
	defer mu.Unlock()
	deposit(-amount)
	if balance < 0 {
		deposit(amount)
		return false // insufficient funds
	}
	return true
}

func Deposit(amount int) {
	mu.Lock()
	defer mu.Unlock()
	deposit(amount)
}

func deposit(amount int) { balance += amount }
