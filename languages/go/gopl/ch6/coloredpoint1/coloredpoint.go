package main

import (
	"fmt"
	"image/color"
	"math"
)

type Point struct {
	X, Y float64
}

type ColoredPoint struct {
	Point
	Color color.RGBA
}

func main() {
	var cp ColoredPoint
	cp.X = 1
	fmt.Println(cp.Point.X) // 1
	cp.Point.Y = 2
	fmt.Println(cp.Y) // 2

	red := color.RGBA{255, 0, 0, 255}
	blue := color.RGBA{0, 0, 255, 255}
	var p = ColoredPoint{Point{1, 1}, red}
	var q = ColoredPoint{Point{5, 4}, blue}
	p.ScaleBy(2)
	q.ScaleBy(2)
	fmt.Println(p.Distance(q.Point))

	// p.Distance(q) // compile ERROR: cannot use q (ColoredPoint) as Point
}

func (p *Point) ScaleBy(factor float64) {
	p.X *= factor
	p.Y *= factor
}

func (p Point) Distance(q Point) float64 {
	return math.Hypot(p.X-q.X, p.Y-q.Y)
}

// func (p ColoredPoint) Distance(q Point) float64 {
// 	return p.Point.Distance(q)
// }

// func (p *ColoredPoint) ScaleBy(factor float64) {
// 	p.Point.ScaleBy(factor)
// }
