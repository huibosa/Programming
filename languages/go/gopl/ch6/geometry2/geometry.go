package main

import (
	"fmt"
	"math"
)

type Point struct{ X, Y float64 }

func (p Point) Distance(q Point) float64 {
	return math.Hypot(q.X-p.Y, q.Y-p.Y)
}

func (p *Point) ScaleBy(factor float64) {
	p.X *= factor
	p.Y *= factor
}

func main() {
	p := Point{1, 2}
	q := Point{4, 6}

	distanceFromP := p.Distance // method value
	fmt.Println(distanceFromP(q))

	var origin Point
	fmt.Println(distanceFromP(origin))

	scaleP := p.ScaleBy // method value
	scaleP(2)           // (2,4)
	scaleP(3)           // (6,12)
	scaleP(10)          // (60, 120)
}
