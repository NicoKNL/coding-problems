package main

import (
	"aoc"
	"fmt"
	"os"
)

type Pos struct {
	r, c int
}

var DIRECTIONS = []Pos{
	{-1, 0}, // Up
	{1, 0},  // Down
	{0, -1}, // Left
	{0, 1},  // Right
}

var AREA = make(map[int]int)
var PERIMETER = make(map[int]int)

func floodFillBFS(grid [][]rune, IDs [][]int, startPos Pos, regionID int, target rune) {
	rows := len(grid)
	cols := len(grid[0])
	visited := make(map[Pos]bool)

	// BFS setup
	queue := []Pos{startPos}
	visited[startPos] = true
	IDs[startPos.r][startPos.c] = regionID

	// Start BFS
	for len(queue) > 0 {
		currentPos := queue[0]
		queue = queue[1:]

		// Traverse neighbors
		for _, direction := range DIRECTIONS {
			newRow := currentPos.r + direction.r
			newCol := currentPos.c + direction.c

			// Check if the new position is valid and matches the target character
			if newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols &&
				!visited[Pos{newRow, newCol}] && grid[newRow][newCol] == target { // Only flood fill same letter
				visited[Pos{newRow, newCol}] = true
				IDs[newRow][newCol] = regionID
				queue = append(queue, Pos{newRow, newCol})
			}
		}
	}
}

func fillGridWithIDs(grid [][]rune) [][]int {
	rows := len(grid)
	cols := len(grid[0])
	IDs := make([][]int, rows)

	// Initialize idGrid with 0s
	for i := range IDs {
		IDs[i] = make([]int, cols)
	}

	ID := 1

	// Run BFS for each unvisited cell
	for r := 0; r < rows; r++ {
		for c := 0; c < cols; c++ {
			if IDs[r][c] == 0 {
				startPos := Pos{r, c}
				target := grid[r][c] // The character we are flooding with
				floodFillBFS(grid, IDs, startPos, ID, target)
				ID++
			}
		}
	}

	return IDs
}

func computeAreas(G [][]int) {
	for r := 0; r < len(G); r += 1 {
		for c := 0; c < len(G[0]); c += 1 {
			AREA[G[r][c]] += 1
		}
	}
}

func computePerimeter(G [][]int) {
	for r := 0; r < len(G); r += 1 {
		prev := -1
		current := -1
		for c := 0; c < len(G[0]); c += 1 {
			current = G[r][c]
			if prev != current {
				if prev != -1 {
					PERIMETER[prev] += 1
				}
				PERIMETER[current] += 1

				prev = current
			}
		}
		PERIMETER[current] += 1
	}
}

func main() {
	G := aoc.ReadRuneGrid(os.Args[1])
	aoc.PrintRuneGrid(G)

	IDs := fillGridWithIDs(G)
	aoc.PrintNumberGrid(IDs)
	fmt.Println(" ")

	computeAreas(IDs)
	computePerimeter(IDs)
	IDs = aoc.RotateNumberGrid(IDs)
	computePerimeter(IDs)
	aoc.PrintNumberGrid(IDs)

	cost := 0
	for area, size := range AREA {
		fmt.Println(area, size, PERIMETER[area])
		cost += PERIMETER[area] * size
	}

	fmt.Println(cost)
}
