package main

import (
	"fmt"
	"io/ioutil"
	"strconv"
	"strings"
	"os"
	"sort")

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func readLines(input_file string) []string {
	data, _ := ioutil.ReadFile(input_file)
	content := string(data)
	return strings.Split(content, "\n")
}

func parseInts(line string) []int {
	fields := strings.Fields(line)
	var numbers []int

	for _, field := range fields {
		num, _ := strconv.Atoi(field)
		numbers = append(numbers, num)
	}

	return numbers
}

func parseInput(input_file string) {
	lines := readLines(input_file)
	var left, right []int
	for _, line := range lines {
		nums := parseInts(line)
		left = append(left, nums[0])
		right = append(right, nums[1])
	}
	sort.Ints(left)
	sort.Ints(right)

	total := 0
	for i := 0; i < len(left); i++ {
		diff := abs(left[i] - right[i])
		total += diff
	}
	fmt.Println(total)
}


func main() {
	parseInput(os.Args[1])

}