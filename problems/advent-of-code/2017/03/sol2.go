package main

import "fmt"

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func makeGrid(rows int, cols int) [][]int {
	grid := make([][]int, rows)
	for i := range grid {
		grid[i] = make([]int, cols)
	}
	return grid
}

type Dir int

const (
	East Dir = iota
	North
	West
	South
)

func sumCells(grid [][]int, row, col int) int {
	sum := 0

	directions := []struct{ row, col int }{
		{-1, -1}, {-1, 0}, {-1, 1},
		{0, -1}, {0, 1},
		{1, -1}, {1, 0}, {1, 1},
	}

	for _, dir := range directions {
		r, c := row+dir.row, col+dir.col
		if r >= 0 && r < len(grid) && c >= 0 && c < len(grid[0]) {
			sum += grid[r][c]
		}
	}

	return sum
}

func main() {
	target := 265149

	G := makeGrid(1000, 1000)
	d := East

	n := 1
	x := 500
	y := 500
	G[x][y] = n

	offset := 1
	remaining := 1
	step := 0

	for true {
		if G[x][y] >= target {
			break
		}
		switch d {
		case East:
			x += 1
		case North:
			y += 1
		case West:
			x -= 1
		case South:
			y -= 1
		}
		G[x][y] = sumCells(G, x, y)
		remaining -= 1

		if remaining == 0 {
			switch d {
			case East:
				d = North
			case North:
				d = West
			case West:
				d = South
			case South:
				d = East
			}

			step += 1
			if step % 2 == 0 {
				offset += 1
			}
			remaining = offset
		}
	}
	fmt.Println(G[x][y])
}
