import sys
from math import sqrt
from sympy import Line, Ray, Plane, Point


def parseLine(line: str) -> Line:
    a, b = line.split("@")
    a = list(map(int, a.split(",")))
    b = list(map(int, b.split(",")))
    a = Point(a)
    b = Point(b)
    return Line(a, a + b)


lines = [line.strip() for line in sys.stdin]
print(lines)
paths = []
for line in lines:
    l = parseLine(line)
    paths.append(l)
# paths = [romStr(s) for s in lines]
print(paths)

l0, l1, l2, l3 = paths[:4]
print(l0, l0.direction)
print(l1, l1.direction)
print(l2, l2.direction)
print(l3, l3.direction)

offset = l0.p1
velocity = l0.p2

# l0 = Line(l0.p1 - offset, l0.p2 - velocity)
l1 = Line(l1.p1 - offset, l1.p2 - velocity)
l2 = Line(l2.p1 - offset, l2.p2 - velocity)
l3 = Line(l3.p1 - offset, l3.p2 - velocity)
print("-" * 20)
print(l0, l0.direction)
print(l1, l1.direction)
print(l2, l2.direction)
print(l3, l3.direction)
MIN = 200000000000000
MAX = 400000000000000
# MIN = 7
# MAX = 27
intersections = 0


p0 = Point(0, 0, 0)
p1 = l1.p1
p2 = l1.p2
print("-" * 20)
print(p0, p1, p2)
plane = Plane(p0, p1, p2)

print(plane)

p3 = plane.intersection(l2)[0]
p4 = plane.intersection(l3)[0]
print("-" * 20)
print(p3, p4)


def getTime(line, point):
    dist = point.distance(line.p1)
    velocity = line.p1.distance(line.p2)
    return dist / velocity


t1 = getTime(l2, p3)
t2 = getTime(l3, p4)

if t1 > t2:
    p3, p4 = p4, p3
print(t1)
print(t2)
print("-" * 20)

dist = p1.distance(p2)
dt = abs(t2 - t1)
print(dist, dt)
print("-" * 20)

# speed = dist / dt
# print(speed)

vel = (p4 - p3) / dt
print(vel)
print("-" * 20)

origin = p3 - vel * t2
origin += offset
print(origin)
print("-" * 20)
print(float(sum(origin.coordinates)))

# common_line = Line(p1, p2)
# print(common_line)

# crossings = []
# for path in paths:
#     crossings.append(common_line.intersection(path)[0])

# points = sorted(crossings, key=lambda p: p.coordinates)
# vec = points[1] - points[0]
# start = points[0] - vec
# print(start)


# MIN = 7
# MAX = 27

# intersections = computeIntersections(stones)
# print(intersections)
