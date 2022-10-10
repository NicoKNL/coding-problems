import sys
import math


def rotate_point(x, y, angle):
    s = math.sin(math.radians(angle))
    c = math.cos(math.radians(angle))

    return (x * c - y * s, x * s + y * c)


def calculateBoundingBoxArea(point_a, point_b):
    print(point_a, point_b)
    min_x = point_a[0]
    max_x = point_b[0]

    min_y = point_a[1]
    max_y = point_b[1]
    print("-------- RESULT: ", abs(max_y - min_y) * abs(max_x - min_x))
    return abs(max_y - min_y) * abs(max_x - min_x)


def calculateAreaForSplit(points, p_i):
    return calculateBoundingBoxArea(points[0], points[p_i]) + calculateBoundingBoxArea(
        points[p_i + 1], points[-1]
    )


def calculateOptimalSplitArea(points, alt_index):
    min_area = sys.maxsize

    alts = sorted([p[alt_index] for p in points])

    heap_l = heapify(alts)
    heap_r = []

    for i in range(len(points) - 1):
        first.remove(points[i][alt_index])
        second.append(points[i])
        second = sorted(second)
        first_area = 
        min_area = min(min_area, calculateAreaForSplit(points, i))
        print("min_area: ", min_area)

    return min_area


def solve():
    point_count = int(input())
    points = []

    for i in range(point_count):
        x, y = [int(_) for _ in input().split(" ")]
        rx, ry = rotate_point(x, y, -0.001)
        points.append((x, y, rx, ry))

    points = sorted(points, key=lambda p: p[2])

    bbox_area = calculateBoundingBoxArea(points[0], points[-1])
    print("bbox_area: ", bbox_area)
    print("=" * 20)
    horizontal_split_area = calculateOptimalSplitArea(points)
    print("hsplit: ", horizontal_split_area)
    print("=" * 20)

    points = sorted(points, key=lambda p: p[3])
    vertical_split_area = calculateOptimalSplitArea(points)
    print("vsplit: ", vertical_split_area)
    print("=" * 20)

    print(min(bbox_area, horizontal_split_area, vertical_split_area))


if __name__ == "__main__":
    T = int(input())

    while T:
        print("=" * 80)
        solve()
        T -= 1