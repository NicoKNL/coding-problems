package main

import (
	"aoc"
	"fmt"
	"os"
	"strings"
)

func convertRules(rules []string) [][]int {
	var result [][]int

	for _, rule := range rules {
		result = append(result, aoc.IntsFromPattern(rule, `(\d+).(\d+)`))
	}
	return result
}

func main() {
	lines := aoc.ReadLines(os.Args[1])
	raw_rules, raw_pages := aoc.SplitOnEmptyString(lines)
	rules := convertRules(raw_rules)

	total := 0

	for _, s := range raw_pages {
		valid := true
		nums := aoc.ParseInts(strings.ReplaceAll(s, ",", " "))
		for i := 0; i < len(nums); i += 1 {
			for ii := i + 1; ii < len(nums); ii += 1 {
				for _, rule := range rules {
					if rule[0] == nums[ii] && rule[1] == nums[i] {
						valid = false
						nums[ii], nums[i] = nums[i], nums[ii]
						if i > 0 {
							i -= 1
						}
						ii = i + 1
					}
				}
			}
		}

		if !valid {
			total += nums[len(nums) / 2]
		}
	}

	fmt.Println(total)
}