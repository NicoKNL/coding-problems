package main

import "fmt"
import "io/ioutil"

func parseInput(input_file string) []rune {
	data, _ := ioutil.ReadFile(input_file)
	return []rune(string(data))
}

func makeCircular(chars []rune) []rune {
	return append(chars, chars[0])
}

func main() {
	chars := parseInput("in")
	chars = makeCircular(chars)

	var total int = 0
	for i := 0; i < len(chars) - 1; i++ {
		a := chars[i]
		b := chars[i + 1]
		if a == b {
			total += int(a) - '0'
		}
	}

	fmt.Println(total)
}