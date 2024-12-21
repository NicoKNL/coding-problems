package main

import (
	"aoc"
	"fmt"
	"math"
	"os"
)

type Vec2 struct {
	x, y int
}

type Robot struct {
	p, v Vec2
}

var W int = 101
var H int = 103
var STEPS int = 1e9

func parseRobots(lines []string) []Robot {
	var robots []Robot

	for i := 0; i < len(lines); i += 1 {
		d := aoc.IntsFromPattern(lines[i], `p=(-?\d+),(-?\d+) v=(-?\d+)\,(-?\d+)`)
		robots = append(robots, Robot{Vec2{d[0], d[1]}, Vec2{d[2], d[3]}})
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

func move(robots []Robot, time int) int {
	for i := 0; i < time; i += 1 {
		for r := range robots {
			robots[r].Step()
		}
		stdDevX, stdDevY := computePositionStandardDeviation(robots)
		if stdDevX < 25 && stdDevY < 25 {
			return i
		}
	}
	return -1
}

func calculateMean(values []float64) float64 {
	sum := 0.0
	for _, v := range values {
		sum += v
	}
	return sum / float64(len(values))
}

func calculateStandardDeviation(values []float64) float64 {
	mean := calculateMean(values)
	sumSquares := 0.0
	for _, v := range values {
		diff := v - mean
		sumSquares += diff * diff
	}
	return math.Sqrt(sumSquares / float64(len(values)))
}

func computePositionStandardDeviation(robots []Robot) (float64, float64) {
	var xValues, yValues []float64

	// Extract x and y coordinates
	for _, robot := range robots {
		xValues = append(xValues, float64(robot.p.x))
		yValues = append(yValues, float64(robot.p.y))
	}

	// Compute standard deviation for x and y
	stdDevX := calculateStandardDeviation(xValues)
	stdDevY := calculateStandardDeviation(yValues)

	return stdDevX, stdDevY
}

func main() {
	lines := aoc.ReadLines(os.Args[1])
	robots := parseRobots(lines)
	fmt.Println(move(robots, STEPS) + 1)
}
