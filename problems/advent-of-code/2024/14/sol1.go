package main

import (
	"aoc"
	"fmt"
	"os"
)

type Vec2 struct {
	x, y int
}

type Robot struct {
	p, v   Vec2
	memory map[Vec2]int
}

var W int = 101
var H int = 103
var STEPS int = 100

func parseRobots(lines []string) []Robot {
	var robots []Robot

	for i := 0; i < len(lines); i += 1 {
		d := aoc.IntsFromPattern(lines[i], `p=(-?\d+),(-?\d+) v=(-?\d+)\,(-?\d+)`)
		robots = append(robots, Robot{Vec2{d[0], d[1]}, Vec2{d[2], d[3]}, make(map[Vec2]int)})
		// robots[i].memory[robots[i].p] = 0
	}

	return robots
}

func (r *Robot) Step() {
	r.p.x = ((r.p.x + r.v.x + W) % W)
	r.p.y = ((r.p.y + r.v.y + H) % H)
}

func (r *Robot) Quadrant() int {
	if r.p.x == W/2 || r.p.y == H/2 {
		return -1
	}

	left := r.p.x < W/2
	top := r.p.y < H/2

	if left && top {
		return 0
	} else if top {
		return 1
	} else if left {
		return 2
	} else {
		return 3
	}
}

func move(robots []Robot, time int) {
	for i := 0; i < time; i += 1 {
		for r := range robots {
			robots[r].Step()
		}
	}
}

func countQuadrants(robots []Robot) []int {
	counter := []int{0, 0, 0, 0}

	for _, robot := range robots {
		quadrant := robot.Quadrant()
		if quadrant >= 0 {
			counter[quadrant] += 1
		}
	}

	return counter
}

func main() {
	lines := aoc.ReadLines(os.Args[1])
	robots := parseRobots(lines)

	move(robots, STEPS)
	quadrants := countQuadrants(robots)

	fmt.Println(quadrants[0] * quadrants[1] * quadrants[2] * quadrants[3])
}
