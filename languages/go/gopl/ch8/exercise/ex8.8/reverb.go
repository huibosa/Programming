// Using a select statement, add a timeout to the echo server from Section 8.3
// so that it disconnects any client that shouts nothing within 10seconds.

package main

import (
	"bufio"
	"fmt"
	"io"
	"log"
	"net"
	"strings"
	"sync"
	"time"
)

func main() {
	tcpAddr, err := net.ResolveTCPAddr("tcp4", "localhost:8000")
	if err != nil {
		log.Fatal(err)
	}
	l, err := net.ListenTCP("tcp4", tcpAddr)
	if err != nil {
		log.Fatal(err)
	}

	for {
		conn, err := l.AcceptTCP()
		if err != nil {
			log.Print(err)
			continue
		}
		go handleConn(conn)
	}
}

func handleConn(c *net.TCPConn) {
	wg := &sync.WaitGroup{}
	defer func() {
		wg.Wait()
		c.Close()
	}()

	lines := make(chan string)
	go scan(c, lines)

	timeout := 5 * time.Second
	timer := time.NewTimer(timeout)
	for {
		select {
		case line := <-lines:
			timer.Reset(timeout)
			wg.Add(1)
			go echo(c, line, 1*time.Second, wg)
		case <-timer.C:
			fmt.Fprintln(c, "long time no input, closing connection")
			return
		}
	}
}

func scan(r io.Reader, lines chan<- string) {
	s := bufio.NewScanner(r)
	for s.Scan() {
		lines <- s.Text()
	}

	if s.Err() != nil {
		log.Print("scan: ", s.Err())
	}
}

func echo(c *net.TCPConn, str string, delay time.Duration, wg *sync.WaitGroup) {
	defer wg.Done()
	fmt.Fprintln(c, "\t", strings.ToUpper(str))
	time.Sleep(delay)
	fmt.Fprintln(c, "\t", strings.Title(str))
	time.Sleep(delay)
	fmt.Fprintln(c, "\t", strings.ToLower(str))
}
