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

	counter := make(map[int]int)
	for _, value := range right {
		counter[value]++
	}

	total := 0

	for _, value := range left {
		total += value * counter[value]
	}

	fmt.Println(total)
}


func main() {
	parseInput(os.Args[1])

}