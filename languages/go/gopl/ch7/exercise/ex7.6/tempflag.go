package main

import (
	"flag"
	"fmt"
)

var tempCelcius = CelsiusFlag("c", 20.0, "the temperature")
var tempFahrenheit = FahrenheitFlag("f", 20.0, "the temperature")
var tempKelvin = KelvinFlag("k", 20.0, "the temperature")

func main() {
	flag.Parse()
	fmt.Println(*tempCelcius)
	fmt.Println(*tempFahrenheit)
	fmt.Println(*tempKelvin)
}
