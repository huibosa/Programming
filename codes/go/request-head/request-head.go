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

	req := "HEAD / HTTP/1.0\r\n\r\n"
	_, err = con.Write([]byte(req))
	if err != nil {
		log.Fatal(err)
	}

	res, err := io.ReadAll(con)
	if err != nil {
		log.Fatal(err)
	}

	fmt.Println(string(res))
}
