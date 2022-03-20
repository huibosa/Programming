package bank

var (
	sema    = make(chan struct{}, 1) // a binary semaphore guarding balance
	balance int
)

var deposits = make(chan int) // send amount to deposit
var balances = make(chan int) // receive balance

func Deposit(amount int) {
	sema <- struct{}{}
	deposits <- amount
	<-sema
}

func Balance() int {
	sema <- struct{}{}
	b := <-balances
	<-sema
	return b
}
