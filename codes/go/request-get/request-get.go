package main

import (
	"fmt"
	"io"
	"log"
	"net"
)

func main() {
	con, err := net.Dial("tcp", "webcode.me:80")
	if err != nil {
		log.Fatal(err)
	}

	req := "GET / HTTP/1.0\r\n" +
		"Host: webcode.me\r\n" +
		"User-Agent: Go client\r\n\r\n"

	_, err = con.Write([]byte(req))
	if err != nil {
		log.Fatal(err)
	}

	msg, err := io.ReadAll(con)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(string(msg))
}
