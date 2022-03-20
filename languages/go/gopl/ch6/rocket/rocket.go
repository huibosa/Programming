package main

import (
	"fmt"
	"time"
)

type rocket struct {
	name string
}

func (r rocket) launch() {
	fmt.Print(r.name, "launched.")
}

func main() {
	r := new(rocket)
	time.AfterFunc(5*time.Second, r.launch)
}
