package aoc

import (
	"fmt"
	"os"
	"regexp"
	"strconv"
	"strings"
)

func Abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func ReadLines(input_file string) []string {
	data, _ := os.ReadFile(input_file)
	content := string(data)
	return strings.Split(content, "\n")
}

func ReadLine(input_file string) string {
	return ReadLines(input_file)[0]
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

func SplitOnEmptyString(input []string) ([]string, []string) {
	for i, s := range input {
		if s == "" {
			return input[:i], input[i+1:]
		}
	}
	return input, nil
}

func IntsFromPattern(input string, pattern string) []int {
	re, _ := regexp.Compile(pattern)
	matches := re.FindStringSubmatch(input)

	var result []int
	for i, match := range matches {
		if i == 0 {
			continue
		}
		num, _ := strconv.Atoi(match)
		result = append(result, num)
	}
	return result
}

func ReadRuneGrid(input_file string) [][]rune {
	strings := ReadLines(input_file)
	// Create a 2D slice of runes
	var grid [][]rune

	// Iterate through each string
	for _, str := range strings {
		// Convert the string to a slice of runes and append to the grid
		grid = append(grid, []rune(str))
	}

	return grid
}

func PrintRuneGrid(grid [][]rune) {
	for _, row := range grid {
		for _, r := range row {
			fmt.Printf("%c", r) // Print each rune as a character
		}
		fmt.Println() // Move to the next line after each row
	}
}

type Set struct {
	items map[string]struct{}
}

func CreateSet() *Set {
	return &Set{
		items: make(map[string]struct{}),
	}
}

// Add inserts an element into the set
func (s *Set) Add(item string) {
	s.items[item] = struct{}{}
}

// Remove deletes an element from the set
func (s *Set) Remove(item string) {
	delete(s.items, item)
}

// Contains checks if an element is in the set
func (s *Set) Contains(item string) bool {
	_, exists := s.items[item]
	return exists
}

// Size returns the number of elements in the set
func (s *Set) Size() int {
	return len(s.items)
}

// Elements returns all elements in the set as a slice
func (s *Set) Elements() []string {
	elements := make([]string, 0, len(s.items))
	for item := range s.items {
		elements = append(elements, item)
	}
	return elements
}
