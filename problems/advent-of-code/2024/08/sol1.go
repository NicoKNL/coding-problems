package main

import (
	"aoc"
	"fmt"
	"os"
)

type Pos struct {
	r, c int
}

func getFrequences(grid [][]rune) map[rune][]Pos {
	M := make(map[rune][]Pos)

	for r := 0; r < len(grid); r += 1 {
		for c := 0; c < len(grid[0]); c += 1 {
			symbol := grid[r][c]
			if symbol != '.' {
				M[symbol] = append(M[symbol], Pos{r, c})
			}
		}
	}

	return M
}

func project(a, b Pos) []Pos {
	dr := b.r - a.r
	dc := b.c - a.c
	return []Pos{{a.r - dr, a.c - dc}, {b.r + dr, b.c + dc}}
}

func solve(grid [][]rune, frequencies map[rune][]Pos) int {
	M := make(map[Pos]bool)

	for _, positions := range frequencies {
		for i := 0; i < len(positions); i += 1 {
			for ii := i + 1; ii < len(positions); ii += 1 {
				nextPositions := project(positions[i], positions[ii])
				for _, p := range nextPositions {
					if 0 <= p.r && p.r < len(grid) && 0 <= p.c && p.c < len(grid[0]) {
						M[p] = true
					}
				}
			}
		}
	}

	for pos, _ := range M {
		grid[pos.r][pos.c] = '#'
	}

	return len(M)
}

func main() {
	grid := aoc.ReadRuneGrid(os.Args[1])
	freqs := getFrequences(grid)
	fmt.Println(solve(grid, freqs))
}
