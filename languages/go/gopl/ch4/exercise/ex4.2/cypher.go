package main

import (
	"bufio"
	"crypto/sha256"
	"crypto/sha512"
	"flag"
	"fmt"
	"os"
)

var use384 = flag.Bool("sha384", false, "SHA384")
var use512 = flag.Bool("sha512", false, "SHA512")

func checkFlags() {
	flag.Parse()
	if *use384 && *use512 {
		fmt.Fprintln(os.Stderr, "can't do both sha384 and 512")
		os.Exit(1)
	}
}

func main() {
	checkFlags()

	for {
		s := bufio.NewScanner(os.Stdin)
		for s.Scan() {
			switch {
			case *use384:
				cypher := sha512.Sum384(s.Bytes())
				fmt.Printf("%x\n", cypher)
			case *use512:
				cypher := sha512.Sum512(s.Bytes())
				fmt.Printf("%x\n", cypher)
			default:
				cypher := sha256.Sum256(s.Bytes())
				fmt.Printf("%x\n", cypher)
			}
		}
	}
}
