package main

import "fmt"
import "io/ioutil"
import "strings"
import "strconv"
import "slices"

func parseLine(s string) []int {
	var row []int
	for _, num := range strings.Split(s, " ") {
		n, _ := strconv.Atoi(num)
		row = append(row, n)
	}
	return row
}

func parseInput(input_file string) [][]int {
	data, _ := ioutil.ReadFile(input_file)
	content := string(data)
	lines := strings.Split(content, "\n")

	var rows [][]int
	for _, line := range lines {
		if len(line) == 0 {
			continue
		}
		rows = append(rows, parseLine(line))
	}
	return rows
}

func main() {
	rows := parseInput("in")

	total := 0
	for _, row := range rows {
		min := slices.Min(row)
		max := slices.Max(row)
		total += max - min
	}
	fmt.Println(total)
}