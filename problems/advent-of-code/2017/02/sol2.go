package main

import "fmt"
import "io/ioutil"
import "strings"
import "strconv"
import "sort"

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

func div(nums []int) int {
	sort.Ints(nums)
	for i := 0; i < len(nums) - 1; i++ {
		for ii := i + 1; ii < len(nums); ii++ {
			if nums[ii] % nums[i] == 0 {
				return nums[ii] / nums[i]
			}
		}
	}
	return -1
}

func main() {
	rows := parseInput("in")

	total := 0
	for _, row := range rows {
		total += div(row)
	}
	fmt.Println(total)
}