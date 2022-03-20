package main

import "os"

func processFiles(fnames []string) error {
	for _, fname := range fnames {
		if err := doFile(fname); err != nil {
			return err
		}
	}
	return nil
}

func doFile(fname string) error {
	f, err := os.Open(fname)
	if err != nil {
		return err
	}
	defer f.Close()
	// process ff
	return nil
}
