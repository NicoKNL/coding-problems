package main

import "fmt"

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func main() {
	target := 265149

	n := 1

	for n * n < target {
		n += 2
	}

	x, y := n / 2, -n / 2
	fmt.Println(x)
	fmt.Println(y)
	value := n * n
	fmt.Println(value)

	steps := n - 1
	for value > target && steps > 0 {
		value -= 1
		steps -= 1
		x -= 1
	}

	steps = n - 1
	for value > target && steps > 0 {
		value -= 1
		steps -= 1
		y += 1
	}

	steps = n - 1
	for value > target && steps > 0 {
		value -= 1
		steps -= 1
		x += 1
	}

	steps = n - 1
	for value > target && steps > 0 {
		value -= 1
		steps -= 1
		y -= 1
	}

	fmt.Println(x, y)
	fmt.Println(abs(x) + abs(y))
}
