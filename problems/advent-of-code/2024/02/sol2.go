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

func resliceWithoutIndex(nums []int, index int) []int {
	result :=make([]int, 0, len(nums)-1)
	result = append(result, nums[:index]...)
	result = append(result, nums[index+1:]...)
	return result
}

func main() {
	lines := aoc.ReadLines(os.Args[1])

	safe := 0

	for _, line := range lines {
		numbers := aoc.ParseInts(line)
		for i := 0; i < len(numbers); i++ {
			newSlice := resliceWithoutIndex(numbers, i)

			if isMonotonic(newSlice) && hasAbsDifferenceOneOrTwoOrThree(newSlice) {
				safe += 1
				break
			}
		}
	}

	fmt.Println(safe)
}