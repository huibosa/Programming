package main

import (
	"fmt"
	"log"
	"net"
)

func main() {
	con, err := net.Dial("tcp", "djxmmx.net:17")
	if err != nil {
		log.Fatal(err)
	}
	defer con.Close()

	msg := ""
	_, err = con.Write([]byte(msg))
	if err != nil {
		log.Fatal(err)
	}

	reply := make([]byte, 1024)
	_, err = con.Read(reply)
	if err != nil {
		log.Fatal(err)
	}

	fmt.Println(string(reply))
}
