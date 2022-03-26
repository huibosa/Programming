package main

import (
	"fmt"
	"os"
)

func main() {
	_, err := os.Open("/no/such/file")
	fmt.Println(err) // open: /no/such/file: no such file or directory
	fmt.Printf("%#v\n", err)
	// Output:
	// &fs.PathError{Op:"open", Path:"/no/such/file", Err:0x2}
	fmt.Println(os.IsNotExist(err))
}
