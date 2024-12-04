package main

import (
	"aoc"
	"fmt"
	"os"
)

func convertToRuneGrid(lines []string) [][]rune {
	var grid [][]rune

	for _, s := range lines {
		grid = append(grid, []rune(s))
	}

	return grid
}

func countXMAS(G [][]rune, r int, c int) int {
	// Define the string to match
	target := []rune("XMAS")

	// Define the eight possible directions (dx, dy)
	directions := [][2]int{
		{0, 1},   // Horizontal right
		{0, -1},  // Horizontal left
		{1, 0},   // Vertical down
		{-1, 0},  // Vertical up
		{1, 1},   // Diagonal down-right
		{1, -1},  // Diagonal down-left
		{-1, 1},  // Diagonal up-right
		{-1, -1}, // Diagonal up-left
	}
	count := 0

	for _, dir := range directions {
		dx, dy := dir[0], dir[1]
		matches := true

		for i := 0; i < 4; i++ {
			nx, ny := r+i*dx, c+i*dy
			if nx < 0 || nx >= len(G) || ny < 0 || ny >= len(G[0]) || G[nx][ny] != target[i] {
				matches = false
				break
			}
		}
		if matches {
			count += 1
		}
	}
	return count
}

func main() {
	lines := aoc.ReadLines(os.Args[1])
	G := convertToRuneGrid(lines)

	rows := len(G)
	cols := len(G[0])
	xmas_count := 0
	for r := 0; r < rows; r++ {
		for c := 0; c < cols; c++ {
			xmas_count += countXMAS(G, r, c)
		}
	}
	fmt.Println(xmas_count)
}