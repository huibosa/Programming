package main

import (
	"fmt"
	"io"
	"log"
	"net/http"
)

func main() {
	ch := make(chan string, 3)

	go func() { ch <- request("http://wechat.com") }()
	go func() { ch <- request("http://qq.com") }()
	go func() { ch <- request("http://taobao.com") }()

	resp := <-ch

	fmt.Println(resp)
}

func request(url string) string {
	resp, err := http.Get(url)
	if err != nil {
		log.Print(err)
	}
	defer resp.Body.Close()

	b, err := io.ReadAll(resp.Body)
	if err != nil {
		log.Print(err)
	}

	return string(b)
}
