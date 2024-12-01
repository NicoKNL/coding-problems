package main

import "fmt"
import "io/ioutil"

func parseInput(input_file string) []rune {
	data, _ := ioutil.ReadFile(input_file)
	return []rune(string(data))
}

func makeCircular(chars []rune) []rune {
	return append(chars, chars...)
}

func main() {
	chars := parseInput("in")
	var length int = len(chars)
	var offset int = len(chars) / 2

	chars = makeCircular(chars)

	var total int = 0
	for i := 0; i < length; i++ {
		a := chars[i]
		b := chars[i + offset]
		if a == b {
			total += int(a) - '0'
		}
	}

	fmt.Println(total)
}