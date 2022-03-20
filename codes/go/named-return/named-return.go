package main

func main() {
	done, _ := bbb()
	done()
}

func aaa() (done func(), err error) {
	return func() {
		print("aaa: done")
	}, nil
}

func bbb() (done func(), _ error) {
	done, err := aaa()
	return func() {
		print("bbb: suprise!")
		done()
	}, err
}
