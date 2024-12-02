package aoc

import "io/ioutil"
import "strconv"
import "strings"


func Abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func ReadLines(input_file string) []string {
	data, _ := ioutil.ReadFile(input_file)
	content := string(data)
	return strings.Split(content, "\n")
}

func ParseInts(line string) []int {
	fields := strings.Fields(line)
	var numbers []int

	for _, field := range fields {
		num, _ := strconv.Atoi(field)
		numbers = append(numbers, num)
	}

	return numbers
}
