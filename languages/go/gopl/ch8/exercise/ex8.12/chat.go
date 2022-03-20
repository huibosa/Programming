// Make the bro adc aster announce the cur rent set of clients to each new
// arrival. This requires that the clients set and the entering and leaving ch
// annel s re cord the client name too. package main
package main

import (
	"bufio"
	"fmt"
	"log"
	"net"
)

type client struct {
	c    chan<- string // an outgoing message channel
	name string
}

var (
	leaving  = make(chan client)
	entering = make(chan client)
	messages = make(chan string) // all incomming client messages
)

func main() {
	listener, err := net.Listen("tcp", "localhost:8000")
	if err != nil {
		log.Fatal(err)
	}

	go broadcaster()

	for {
		conn, err := listener.Accept()
		if err != nil {
			log.Print(err)
			continue
		}
		go handleConn(conn)
	}
}

func broadcaster() {
	clients := make(map[client]bool) // all connected clients

	for {
		select {
		case msg := <-messages:
			// Broadcast incoming message to all
			// clients' outgoing message channels.
			for cli := range clients {
				cli.c <- msg
			}
		case cli := <-entering:
			clients[cli] = true
			fmt.Println(clients)
			broadcastWelcome(clients)
		case cli := <-leaving:
			delete(clients, cli)
			close(cli.c)
		}
	}
}

func broadcastWelcome(clients map[client]bool) {
	cliNames := makeCliNames(clients)

	messages <- cliNames
}

func makeCliNames(clients map[client]bool) string {
	ret := string("Current online client: \n")
	for cli := range clients {
		ret += cli.name
		ret += ", "
	}
	ret += "\n"

	return ret
}

func handleConn(conn net.Conn) {
	ch := make(chan string) // outgoing client messages

	go clientWriter(conn, ch)

	who := conn.RemoteAddr().String()
	ch <- "You are " + who
	messages <- who + " has arrived"
	entering <- client{ch, who}

	input := bufio.NewScanner(conn)
	for input.Scan() {
		messages <- who + ": " + input.Text()
	} // NOTE: ignoring potential error from input.Err()

	leaving <- client{ch, who}
	messages <- who + " has left"
	conn.Close()
}

func clientWriter(conn net.Conn, ch <-chan string) {
	for msg := range ch {
		fmt.Fprintln(conn, msg) // NOTE: ignoring network errors
	}
}
