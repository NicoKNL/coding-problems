package main

import (
	"aoc"
	"os"
	"fmt"
)

type Vec2 struct {
	x, y int
}

var DIRECTIONS = [][]int{
	{-1, 0}, // North
	{0, 1},  // East
	{1, 0},  // South
	{0, -1}, // West
}

func findStart(grid [][]rune) Vec2 {
	for x := 0; x < len(grid); x++ {
		for y := 0; y < len(grid[x]); y++ {
			if grid[x][y] == '^' {
				return Vec2{x, y}
			}
		}
	}

	return Vec2{}
}

func traverseAndMark(grid [][]rune) [][]rune {
	start := findStart(grid)

	grid[start.x][start.y] = 'X'

	dir := 0

	x, y := start.x, start.y
	for {
		nextX := x + DIRECTIONS[dir][0]
		nextY := y + DIRECTIONS[dir][1]

		if nextX < 0 || nextY < 0 || nextX >= len(grid) || nextY >= len(grid[0]) {
			break
		}

		if grid[nextX][nextY] == '#' {
			dir = (dir + 1) % 4
		} else {
			grid[nextX][nextY] = 'X'
			x, y = nextX, nextY
		}
	}

	return grid
}

func countX(grid [][]rune) int {
	count := 0
	for _, row := range grid {
		for _, r := range row {
			if r == 'X' {
				count++
			}
		}
	}
	return count
}

func main() {
	grid := aoc.ReadRuneGrid(os.Args[1])
	grid = traverseAndMark(grid)
	fmt.Println(countX(grid))
}