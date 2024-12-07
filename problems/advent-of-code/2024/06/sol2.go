package main

import (
	"aoc"
	"os"
	"fmt"
)

type Vec2 struct {
    x, y int
}

var COUNTER = make(map[Vec2]bool)

func addToSet(x, y int) {
    COUNTER[Vec2{x, y}] = true
}

func isInSet(x, y int) bool {
    return COUNTER[Vec2{x, y}]
}

var DIRECTIONS = [][]int{
	{-1, 0}, // North
	{0, 1},  // East
	{1, 0},  // South
	{0, -1}, // West
}

var SYMBOLS = []rune{'^', '>', 'v', '<'}

func nextDir(dir int) int {
	return (dir + 1) % 4
}

func copyGrid(src [][]rune) [][]rune {
    n := len(src)
    m := len(src[0])
    dst := make([][]rune, n)

    for i := 0; i < n; i++ {
        dst[i] = make([]rune, m)
        copy(dst[i], src[i])
    }

    return dst
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

func traverseAndMark(grid [][]rune) ([][]rune, bool) {
	start := findStart(grid)
	grid[start.x][start.y] = 'X'

	steps := 0
	dir := 0

	x, y := start.x, start.y
	for {
		steps += 1
		if steps > 10000 {
			return grid, true
		}

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

	return grid, false
}


func findXPositions(grid [][]rune) []Vec2 {
    var positions []Vec2

    for i, row := range grid {
        for j, cell := range row {
            if cell == 'X' {
                positions = append(positions, Vec2{x: i, y: j})
            }
        }
    }

    return positions
}

func processOptions(grid [][]rune, positions []Vec2, start Vec2) int{
	counter := 0
	for _, pos := range positions {
		if pos == start {
			continue
		}

		TMP := copyGrid(grid)
		TMP[pos.x][pos.y] = '#'
		if _, loops := traverseAndMark(TMP); loops {
			counter += 1
		}
	}
	return counter
}

func main() {
	grid := aoc.ReadRuneGrid(os.Args[1])

	TMP := copyGrid(grid)
	start := findStart(TMP)
	TMP, _ = traverseAndMark(TMP)
	positions := findXPositions(TMP)
	count := processOptions(grid, positions, start)

	fmt.Println(count)
}