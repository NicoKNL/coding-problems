package main

import (
	"aoc"
	"fmt"
	"os"
)

type Pos struct {
	r, c int
}

// Edge represents a pair of 2D coordinates.
type Edge struct {
	point1, point2 Pos
}

// Check if two perpendicular edges intersect.
func doIntersectPerpendicular(e1, e2 Edge) bool {
	return e2.point1.c > min(e1.point1.c, e1.point2.c) && e2.point1.c < max(e1.point1.c, e1.point2.c) &&
		e1.point1.r > min(e2.point1.r, e2.point2.r) && e1.point1.r < max(e2.point1.r, e2.point2.r)
}

// Helper functions for min and max.
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// UnionFind struct to manage the union-find structure.
type UnionFind struct {
	parent map[Pos]Pos // Tracks the parent of each Pos
	rank   map[Pos]int // Tracks the rank (or depth) of each Pos
}

// NewUnionFind creates a new UnionFind instance.
func NewUnionFind() *UnionFind {
	return &UnionFind{
		parent: make(map[Pos]Pos),
		rank:   make(map[Pos]int),
	}
}

// Find finds the root of the given Pos with path compression.
func (uf *UnionFind) Find(p Pos) Pos {
	if _, exists := uf.parent[p]; !exists {
		uf.parent[p] = p // Set Pos as its own parent if it's not already in the parent map
	}

	if uf.parent[p] != p {
		uf.parent[p] = uf.Find(uf.parent[p]) // Path compression
	}
	return uf.parent[p]
}

// Union unites two points if they belong to different sets.
func (uf *UnionFind) Union(p1, p2 Pos) {
	root1 := uf.Find(p1)
	root2 := uf.Find(p2)

	if root1 != root2 {
		// Union by rank: Attach the tree with lesser rank to the tree with higher rank.
		if uf.rank[root1] > uf.rank[root2] {
			uf.parent[root2] = Pos{root1.r, root1.c}
		} else if uf.rank[root1] < uf.rank[root2] {
			uf.parent[root1] = Pos{root2.r, root2.c}
		} else {
			uf.parent[root2] = Pos{root1.r, root1.c}
			uf.rank[root1]++ // Increment rank if they are of the same rank
		}
	}
}

// IsConnected checks if two points are in the same set.
func (uf *UnionFind) IsConnected(p1, p2 Pos) bool {
	return uf.Find(p1) == uf.Find(p2)
}

// AddEdge joins two points by creating an edge.
func (uf *UnionFind) AddEdge(edge Edge) {
	uf.Union(edge.point1, edge.point2)
}

// NumberOfSets returns the number of disjoint sets by counting the unique roots.
func (uf *UnionFind) NumberOfSets() int {
	rootSet := make(map[Pos]bool)
	for p := range uf.parent {
		rootSet[uf.parent[p]] = true
	}
	return len(rootSet)
}

var DIRECTIONS = []Pos{
	{-1, 0}, // Up
	{1, 0},  // Down
	{0, -1}, // Left
	{0, 1},  // Right
}

var AREA = make(map[int]int)
var PERIMETER = make(map[int]int)
var H_EDGES = make(map[int]*UnionFind)
var V_EDGES = make(map[int]*UnionFind)
var EDGES = make(map[int]map[Edge]bool)

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
	H_EDGES[ID] = NewUnionFind()
	V_EDGES[ID] = NewUnionFind()
	EDGES[ID] = make(map[Edge]bool)

	// Run BFS for each unvisited cell
	for r := 0; r < rows; r++ {
		for c := 0; c < cols; c++ {
			if IDs[r][c] == 0 {
				startPos := Pos{r, c}
				target := grid[r][c] // The character we are flooding with
				floodFillBFS(grid, IDs, startPos, ID, target)
				ID++
				H_EDGES[ID] = NewUnionFind()
				V_EDGES[ID] = NewUnionFind()
				EDGES[ID] = make(map[Edge]bool)
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

func markEdges(G [][]int) {
	// Horizontally
	for r := 0; r < len(G); r += 1 {
		prev := -1
		current := -1
		edge := Edge{Pos{-1, -1}, Pos{-1, -1}}
		for c := 0; c < len(G[0]); c += 1 {
			edge = Edge{Pos{r, c}, Pos{r + 1, c}}
			current = G[r][c]
			if prev != current {
				if prev != -1 {
					H_EDGES[prev].AddEdge(edge)
					EDGES[prev][edge] = true
				}
				H_EDGES[current].AddEdge(edge)
				EDGES[current][edge] = true

				prev = current
			}

		}
		c := len(G[0]) // Col outside grid
		edge = Edge{Pos{r, c}, Pos{r + 1, c}}
		H_EDGES[current].AddEdge(edge)
		EDGES[current][edge] = true
	}

	// Vertically
	for c := 0; c < len(G[0]); c += 1 {
		prev := -1
		current := -1
		edge := Edge{Pos{-1, -1}, Pos{-1, -1}}
		for r := 0; r < len(G[0]); r += 1 {
			edge = Edge{Pos{r, c}, Pos{r, c + 1}}
			current = G[r][c]
			if prev != current {
				if prev != -1 {
					V_EDGES[prev].AddEdge(edge)
					EDGES[prev][edge] = true
				}
				V_EDGES[current].AddEdge(edge)
				EDGES[current][edge] = true

				prev = current
			}

		}

		r := len(G) // Row outside grid
		V_EDGES[current].AddEdge(Edge{Pos{r, c}, Pos{r, c + 1}})
		EDGES[current][edge] = true // = append(EDGES[current], edge)
	}
}

func checkStarPattern(edges []Edge) int {
	pointCount := make(map[Pos]int)

	for _, edge := range edges {
		pointCount[edge.point1]++
		pointCount[edge.point2]++
	}

	centerCount := 0
	for _, count := range pointCount {
		if count == 4 {
			centerCount++
		}
	}

	return centerCount
}

func countCrosses() map[int]int {
	crosses := make(map[int]int)

	for area, edges := range EDGES {
		var edgeKeys []Edge
		for edge := range edges {
			edgeKeys = append(edgeKeys, edge)
		}
		crosses[area] = checkStarPattern(edgeKeys)
	}
	return crosses
}

func main() {
	G := aoc.ReadRuneGrid(os.Args[1])
	IDs := fillGridWithIDs(G)
	computeAreas(IDs)
	markEdges(IDs)
	crosses := countCrosses()

	cost := 0
	for area, size := range AREA {
		cost += (H_EDGES[area].NumberOfSets() + V_EDGES[area].NumberOfSets() + crosses[area]*2) * size
	}

	fmt.Println(cost)
}
