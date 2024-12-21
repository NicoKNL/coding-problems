package main

import (
	"aoc"
	"os"
)

type Pos struct {
	r int
	c int
}

var ANS int
var DIRECTIONS = [][]int{
	{0, -1}, // Left
	{-1, 0}, // Up
	{0, 1},  // Right
	{1, 0},  // Down
}
var VISITED = make(map[Pos]bool)

func explore(G [][]int, r, c int) {
	if G[r][c] == 9 {
		VISITED[Pos{r, c}] = true
		return
	}

	for _, dir := range DIRECTIONS {
		next_r := r + dir[0]
		next_c := c + dir[1]

		if next_r >= 0 && next_r < len(G) && next_c >= 0 && next_c < len(G[0]) {
			if G[next_r][next_c] == (G[r][c] + 1) {
				explore(G, next_r, next_c)
			}
		}
	}

}

func main() {
	G := aoc.ReadNumberGrid(os.Args[1])
	ANS = 0

	for r := 0; r < len(G); r += 1 {
		for c := 0; c < len(G[0]); c += 1 {
			if G[r][c] == 0 {
				VISITED = make(map[Pos]bool)
				explore(G, r, c)
				ANS += len(VISITED)
			}
		}
	}

	println(ANS)
}
