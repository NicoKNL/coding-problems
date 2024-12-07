package main

import (
	"aoc"
	"os"
	"fmt"
	"strconv"
	"strings"
)

type State struct {
	value int
	index int
}

func add(a, b int) int {
	return a + b
}

func mul(a, b int) int {
	return a * b
}

func concat(a, b int) int {
	strA := strconv.Itoa(a)
	strB := strconv.Itoa(b)

	concatenated := strA + strB

	result, _ := strconv.Atoi(concatenated)
	return result
}

var OPS = []func(int, int) int {
	add,
	mul,
	concat,
}

func isValidEquation(s string) (int, bool) {
	parts := strings.Split(s, ":")
	target, _ := strconv.Atoi(parts[0])
	nums := aoc.ParseInts(parts[1])

	Q := []State{{nums[0], 1}}
	i := 0
	for i < len(Q) {
		current := Q[i]
		i += 1

		if current.index >= len(nums) {
			continue
		}

		nextNum := nums[current.index]

		for _, op := range OPS {
			newValue := op(current.value, nextNum)
			if current.index == len(nums) - 1 && newValue == target {
				return target, true
			}

			if newValue <= target {
				Q = append(Q, State{newValue, current.index + 1})
			}
		}
	}

	return target, false
}

func main() {
	total := 0
	for _, line := range aoc.ReadLines(os.Args[1]) {
		if target, isValid := isValidEquation(line); isValid {
			total += target
		}
	}
	fmt.Println(total)
}