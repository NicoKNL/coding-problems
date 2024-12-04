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
	target1 := []rune("MAS") // Normal order
	target2 := []rune("SAM") // Reverse order

	// Define the two diagonal directions to check
	diagonals := [][2]int{
		{-1, -1}, {1, 1}, // Top-left to bottom-right
		{-1, 1}, {1, -1}, // Top-right to bottom-left
	}

	matchcount := 0
	for i := 0; i < len(diagonals); i += 2 {
		for _, target := range [][]rune{target1, target2} {
			matches := true
			for j := 0; j < 3; j++ {
				nx := r + (j-1)*diagonals[i][0] // Shifts -1, 0, +1 for MAS/SAM on the diagonal
				ny := c + (j-1)*diagonals[i][1]

				if nx < 0 || nx >= len(G) || ny < 0 || ny >= len(G[0]) || G[nx][ny] != target[j] {
					matches = false
					break
				}
			}

			if matches {
				matchcount += 1
			}
		}
	}

	if matchcount == 2 {
		return 1
	}
	return 0
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