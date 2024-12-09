package main

import (
	"aoc"
	"os"
)

type Segment struct {
	id    int
	count int
}

func convert(s string) []Segment {
	var disk []Segment

	id := 0
	for i, r := range s {
		count := int(r - '0')
		if count > 0 {
			if i%2 == 0 {
				disk = append(disk, Segment{id, count})
				id += 1
			} else {
				disk = append(disk, Segment{-1, count})
			}
		}
	}

	return disk
}

func show(disk []Segment) {
	for _, space := range disk {
		for i := 0; i < space.count; i += 1 {
			if space.id == -1 {
				print(".")
			} else {
				print(space.id)
			}
		}
	}
	print("\n")
}

func defrag(disk []Segment) []Segment {
	R := len(disk) - 1

	for R > 0 {
		if disk[R].id == -1 {
			R -= 1
			continue
		}

		// Scan for space
		for L := 0; L <= R; L += 1 {
			if disk[L].id != -1 {
				continue
			} else if disk[L].count == disk[R].count {
				disk[L].id = disk[R].id
				disk[R].id = -1
				break
			} else if disk[L].count > disk[R].count {
				disk[L].count -= disk[R].count
				disk = append(disk[:L], append([]Segment{{disk[R].id, disk[R].count}}, disk[L:]...)...)
				R += 1 // compensate for split of empty segment
				disk[R].id = -1
				break
			}
		}
		R -= 1
	}

	return disk
}

func checksum(disk []Segment) int {
	result := 0
	i := 0
	for _, segment := range disk {
		if segment.id == -1 {
			i = i + segment.count
			continue
		}
		n := segment.count
		start := i
		end := start + segment.count - 1

		segment_sum := n * (start + end) / 2
		result += segment.id * segment_sum
		i = i + segment.count
	}

	return result
}

func main() {
	s := aoc.ReadLine(os.Args[1])
	disk := convert(s)
	println(checksum(defrag(disk)))
}
