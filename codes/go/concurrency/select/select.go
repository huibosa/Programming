package main

import "time"

func TryReceive(c <-chan int) (data int, more, ok bool) {
	select {
	case data, more = <-c:
		return data, more, true
	default: // processed when c is blocked
		return 0, true, false
	}
}

// you know at certain time point there will be no message, but you want to
// wait for that message
func TryReceiveWithTimeout(c <-chan int, duration time.Duration) (data int, more, ok bool) {
	select {
	case data, more = <-c:
		return data, more, true
	case <-time.After(duration): // time.After returns a channel
		return 0, true, false
	}
}

func Fanout(In <-chan int, OutA, OutB chan int) {
	for data := range In {
		select {
		case OutA <- data:
		case OutB <- data:
		}
	}
}
