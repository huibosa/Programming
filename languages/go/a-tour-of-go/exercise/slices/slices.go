package main

import "golang.org/x/tour/pic"

// func Pic(dx, dy int) [][]uint8 {
// 	var pic [][]uint8

// 	for i := 0; i < dx; i++ {
// 		var c []uint8
// 		for j := 0; j < dy; j++ {
// 			c = append(c, uint8((i+j)/2))
// 		}
// 		pic = append(pic, c)
// 	}

// 	return pic
// }

func Pic(dx, dy int) [][]uint8 {
	pic := make([][]uint8, dy)
	for x := range pic {
		pic[x] = make([]uint8, dx)
		for y := range pic[x] {
			pic[x][y] = uint8((x + y) / 2)
		}
	}

	return pic
}

func main() {
	pic.Show(Pic)
}
