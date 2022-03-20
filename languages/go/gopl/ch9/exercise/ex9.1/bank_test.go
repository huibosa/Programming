package bank

import (
	"fmt"
	"testing"
)

func TestBank(t *testing.T) {
	done := make(chan struct{})

	// Alice
	go func() {
		Deposit(200)
		Withdraw(200)
		fmt.Println("=", Balance())
		done <- struct{}{}
	}()

	// Bob
	go func() {
		Deposit(50)
		Withdraw(50)
		Deposit(100)
		done <- struct{}{}
	}()

	// Wait for both transactions.
	<-done
	<-done

	if got, want := Balance(), 100; got != want {
		t.Errorf("Balance = %d, want %d", got, want)
	}
}

func TestWithdrawal(t *testing.T) {
	b1 := Balance()
	Withdraw(50)
	expected := b1 - 50
	if b2 := Balance(); b2 != expected {
		t.Errorf("balance = %d, want %d", b2, expected)
	}
}

func TestWithdrawalFailsIfInsufficientFunds(t *testing.T) {
	b1 := Balance()
	Withdraw(b1 + 1)
	b2 := Balance()
	if b2 != b1 {
		t.Errorf("balance = %d, want %d", b2, b1)
	}
}
