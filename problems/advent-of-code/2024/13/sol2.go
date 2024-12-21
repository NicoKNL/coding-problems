package main

import (
	"aoc"
	"fmt"
	"os"
)

type Vec2 struct {
	x, y int
}

type Machine struct {
	a, b, prize Vec2
}

func parseMachines(lines []string) []Machine {
	var machines []Machine

	for i := 0; i < len(lines); i += 4 {
		a := aoc.IntsFromPattern(lines[i], `.*X\+(\d+).*Y\+(\d+).*`)
		b := aoc.IntsFromPattern(lines[i+1], `.*X\+(\d+).*Y\+(\d+).*`)
		prize := aoc.IntsFromPattern(lines[i+2], `.*X=(\d+).*Y=(\d+).*`)

		machines = append(machines, Machine{Vec2{a[0], a[1]}, Vec2{b[0], b[1]}, Vec2{prize[0], prize[1]}})
	}

	return machines
}

type State struct {
	pos  Vec2
	cost int
}

func linearCombinationInt(v1, v2, target Vec2) int {
	x1, y1 := v1.x, v1.y
	x2, y2 := v2.x, v2.y
	s, t := target.x, target.y

	det := x1*y2 - x2*y1
	if det == 0 {
		return 0
	}

	// Check if (s, t) lies in the integer span of v1 and v2
	if (s*y2-t*x2)%det != 0 || (t*x1-s*y1)%det != 0 {
		return 0
	}

	a := (s*y2 - t*x2) / det
	b := (t*x1 - s*y1) / det
	return a*3 + b
}

func main() {
	lines := aoc.ReadLines(os.Args[1])
	machines := parseMachines(lines)

	cost := 0
	for _, machine := range machines {
		cost += linearCombinationInt(machine.a, machine.b, Vec2{machine.prize.x + 10000000000000, machine.prize.y + 10000000000000})
	}

	fmt.Println(cost)
}
