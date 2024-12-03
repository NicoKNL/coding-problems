package main

import (
	"aoc"
	"fmt"
	"os"
	"regexp"
	"strconv"
)



func main() {
	lines := aoc.ReadLines(os.Args[1])

	total := 0
	pattern := `mul\((\d+),(\d+)\)`
	re := regexp.MustCompile(pattern)

	for _, line := range lines {
		matches := re.FindAllStringSubmatch(line, -1)

		for _, match := range matches {
			x, _ := strconv.Atoi(string(match[1]))
			y, _ := strconv.Atoi(string(match[2]))
			fmt.Println(x)
			fmt.Println(y)
			fmt.Println("---")
			total += x * y
		}
	}

	fmt.Println(total)
}