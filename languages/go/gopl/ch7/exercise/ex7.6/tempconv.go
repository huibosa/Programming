package main

import (
	"flag"
	"fmt"
)

type Celsius float64
type Fahrenheit float64
type Kelvin float64
type celsiusFlag struct{ Celsius }
type fahrenheitFlag struct{ Fahrenheit }
type kelvinFlag struct{ Kelvin }

const (
	AbsoluteZeroC Celsius = -273.15
	FreezingC     Celsius = 0
	BoilingC      Celsius = 100
)

func (c Celsius) String() string    { return fmt.Sprintf("%g°C", c) }
func (f Fahrenheit) String() string { return fmt.Sprintf("%g°F", f) }
func (k Kelvin) String() string     { return fmt.Sprintf("%g°K", k) }

func (f *celsiusFlag) Set(s string) error {
	var value float64
	var unit string

	fmt.Sscanf(s, "%f%s", &value, &unit) // no error check needed
	switch unit {
	case "C", "°C":
		f.Celsius = Celsius(value)
		return nil
	case "F", "°F":
		f.Celsius = FToC(Fahrenheit(value))
		return nil
	case "K", "°K":
		f.Celsius = KToC(Kelvin(value))
		return nil
	}
	return fmt.Errorf("invalid temperature %q", s)
}

func (f *fahrenheitFlag) Set(s string) error {
	var value float64
	var unit string

	fmt.Sscanf(s, "%f%s", &value, &unit)
	switch unit {
	case "C", "°C":
		f.Fahrenheit = CToF(Celsius(value))
		return nil
	case "F", "°F":
		f.Fahrenheit = Fahrenheit(value)
		return nil
	case "K", "°K":
		f.Fahrenheit = KToF(Kelvin(value))
		return nil
	}
	return fmt.Errorf("invalid temperature %q", s)
}

func (f *kelvinFlag) Set(s string) error {
	var value float64
	var unit string

	fmt.Sscanf(s, "%f%s", &value, &unit)
	switch unit {
	case "C", "°C":
		f.Kelvin = CToK(Celsius(value))
		return nil
	case "F", "°F":
		f.Kelvin = FToK(Fahrenheit(value))
		return nil
	case "K", "°K":
		f.Kelvin = Kelvin(value)
		return nil
	}
	return fmt.Errorf("invalid temperature %q", s)
}

func CelsiusFlag(name string, value Celsius, usage string) *Celsius {
	f := celsiusFlag{value}
	flag.CommandLine.Var(&f, name, usage)
	return &f.Celsius
}

func FahrenheitFlag(name string, value Fahrenheit, usage string) *Fahrenheit {
	f := fahrenheitFlag{value}
	flag.CommandLine.Var(&f, name, usage)
	return &f.Fahrenheit
}

func KelvinFlag(name string, value Kelvin, usage string) *Kelvin {
	f := kelvinFlag{value}
	flag.CommandLine.Var(&f, name, usage)
	return &f.Kelvin
}
