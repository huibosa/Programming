// Add a function Withdraw(amount int) bool to the gopl.io/ch9/bank1 program. The
// result should indicate whether the transaction succeeded or failed due to
// insufficient funds. The message sent to the monitor goroutine must contain
// both the amount to withdraw and a new channel over which the monitor goroutine
// can send the boolean result back to Withdraw.
package bank

import (
	"fmt"
	"os"
)

var deposits = make(chan int)
var balances = make(chan int)
var withDrawSuccess = make(chan bool)

func Deposit(amount int) { deposits <- amount }
func Balance() int       { return <-balances }

func Withdraw(amount int) {
	Deposit(-amount) // NOTE: don't create another goroutine

	if ok := <-withDrawSuccess; !ok {
		fmt.Fprint(os.Stderr, "WARNING:\tWithdraw() --> balance underflow\n")
	}
}

func teller() {
	var balance int

	for {
		select {
		case amount := <-deposits:
			switch {
			case amount < 0: // withdraw
				if balance+amount >= 0 {
					balance += amount
					withDrawSuccess <- true
				} else {
					withDrawSuccess <- false
				}
			default: // deposit
				balance += amount
			}
		case balances <- balance:
		}
	}
}

func init() {
	go teller()
}
