package rmdirs

import "os"

func rmdirs1() {
	var rmdirs []func()

	for _, d := range tempDirs() {
		dir := d
		os.MkdirAll(dir, 0755)
		rmdirs = append(rmdirs, func() {
			os.RemoveAll(dir)
		})
	}

	for _, rmdir := range rmdirs {
		rmdir()
	}

}

func rmdirs2() {
	var rmdirs []func()

	dirs := tempDirs()

	for i := 0; i < len(dirs); i++ {
		os.MkdirAll(dirs[i], 0755) // OK
		rmdirs = append(rmdirs, func() {
			os.RemoveAll(dirs[i]) // NOTE: incorrect!
		})
	}

	for _, rmdir := range rmdirs {
		rmdir()
	}
}

func tempDirs() []string
