package main

import "aoc"
import "os"
import "fmt"

func isMonotonic(nums []int) bool {
	if len(nums) <= 1 {
		return true
	}

	increasing := true
	decreasing := true

	for i := 1; i < len(nums); i++ {
		if nums[i] > nums[i-1] {
			decreasing = false
		}
		if nums[i] < nums[i-1] {
			increasing = false
		}
	}

	return increasing || decreasing
}

func hasAbsDifferenceOneOrTwoOrThree(nums []int) bool {
	for i := 1; i < len(nums); i++ {
		diff := aoc.Abs(nums[i] - nums[i-1])
		if diff != 1 && diff != 2 && diff != 3 {
			return false
		}
	}
	return true
}

func main() {
	lines := aoc.ReadLines(os.Args[1])

	safe := 0

	for _, line := range lines {
		numbers := aoc.ParseInts(line)
		if isMonotonic(numbers) && hasAbsDifferenceOneOrTwoOrThree(numbers) {
			safe += 1
		}
	}

	fmt.Println(safe)
}