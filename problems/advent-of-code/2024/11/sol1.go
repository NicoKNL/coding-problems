package main

import (
	"aoc"
	"fmt"
	"math"
	"os"
)

func hasEvenDigits(n int) bool {
	// Find the number of digits using logarithm
	digitCount := int(math.Log10(float64(n))) + 1

	// Check if the digit count is even
	return digitCount%2 == 0
}

func splitStone(stone int) (int, int) {
	// Find the number of digits in n
	digitCount := int(math.Log10(float64(stone))) + 1

	// Calculate the power of 10 to split the number
	divider := int(math.Pow(10, float64(digitCount/2)))

	// Split the number into two parts
	left := stone / divider
	right := stone % divider

	return left, right
}

func step(stones map[int]int) map[int]int {
	new_stones := make(map[int]int)

	for stone, count := range stones {
		if stone == 0 {
			new_stones[1] += count
		} else if hasEvenDigits(stone) {
			left, right := splitStone(stone)
			new_stones[left] += count
			new_stones[right] += count
		} else {
			new_stones[stone*2024] += count
		}
	}

	return new_stones
}

func main() {
	nums := aoc.ParseInts(aoc.ReadLine(os.Args[1]))
	stones := make(map[int]int)
	for _, num := range nums {
		stones[num] = 1
	}

	for i := 0; i < 25; i += 1 {
		stones = step(stones)
	}

	total := 0
	for _, count := range stones {
		total += count
	}
	fmt.Println(total)
}
