import sys
from math import sqrt
from sympy import Ray, Plane, Point


def parseLine(line: str) -> Ray:
    a, b = line.split("@")
    a = list(map(int, a.split(",")))[:2]
    b = list(map(int, b.split(",")))[:2]
    a = Point(a)
    b = Point(b)
    return Ray(a, a + b)


lines = [line.strip() for line in sys.stdin]
print(lines)
paths = []
for line in lines:
    ray = parseLine(line)
    print(ray.direction)
    paths.append(ray)
# paths = [romStr(s) for s in lines]
print(paths)

MIN = 200000000000000
MAX = 400000000000000
# MIN = 7
# MAX = 27
intersections = 0

for i in range(len(paths)):
    print(i)
    for ii in range(i + 1, len(paths)):
        isect = paths[i].intersection(paths[ii])
        # print("isect: ", isect)
        if isect:
            x, y = isect[0].coordinates
            if MIN <= x <= MAX and MIN <= y <= MAX:
                intersections += 1

print(intersections)

# MIN = 7
# MAX = 27

# intersections = computeIntersections(stones)
# print(intersections)
