package main

import (
	"aoc"
	"fmt"
	"os"
	"regexp"
	"strconv"
	"strings"
)



func main() {
	lines := aoc.ReadLines(os.Args[1])

	total := 0
	pattern := `mul\((\d+),(\d+)\)|do\(\)|don't\(\)`
	re := regexp.MustCompile(pattern)
	scan := true
	for _, line := range lines {
		matches := re.FindAllStringSubmatch(line, -1)

		for _, match := range matches {
			fmt.Println(match)
			if strings.HasPrefix(match[0], "don't") {
				scan = false
			} else if strings.HasPrefix(match[0], "do") {
				scan = true
			} else {
				if scan {
					x, _ := strconv.Atoi(string(match[1]))
					y, _ := strconv.Atoi(string(match[2]))
					total += x * y
				}
			}
		}
	}

	fmt.Println(total)
}