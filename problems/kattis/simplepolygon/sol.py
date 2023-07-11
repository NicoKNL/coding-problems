from random import random
from math import sqrt, atan2, degrees


class Point:
    def __init__(self, uid, x, y):
        self.id = uid
        self.x = x + random() / 1e9
        self.y = y + random() / 1e9

        self.r = 0
        self.theta = 0

    def computePolar(self, center):
        x = self.x - center.x
        y = self.y - center.y

        self.r = sqrt(x * x + y * y)
        self.theta = degrees(atan2(y, x))


def solve():
    data = list(map(int, input().split()))
    n = data[0]

    points = []
    avg_x = 0
    avg_y = 0
    for i in range(1, 2 * n, 2):
        x, y = data[i], data[i + 1]
        points.append(Point(i // 2, x, y))

        avg_x += points[-1].x
        avg_y += points[-1].y

    center = Point(-1, avg_x / n, avg_y / n)

    for p in points:
        p.computePolar(center)

    points.sort(key=lambda p: -p.r)
    points.sort(key=lambda p: p.theta)

    print(" ".join([str(p.id) for p in points]))


if __name__ == "__main__":
    cases = int(input())

    for i in range(cases):
        solve()
