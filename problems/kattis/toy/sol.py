from itertools import permutations
from math import sqrt, acos


class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return f"({self.x}, {self.y})"

    def __repr__(self):
        return self.__str__()


def linelen(a, b):
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2))


def can_form_triangle(a, b, c):
    if a + b <= c:
        return False

    if a + c <= b:
        return False

    if b + c <= a:
        return False

    return True


def solve(pieces):
    base = [[Point(0, 0), Point(0, pieces[0])]]
    max_x = 0.0
    for i in range(1, len(pieces), 2):
        if i + 1 >= len(pieces):
            return max_x

        next_base = []
        for each in base:

            if not can_form_triangle(linelen(*each), pieces[i], pieces[i + 1]):
                continue

            next_base.extend(extend(each[0], pieces[i], each[1], pieces[i + 1]))

        for each in next_base:
            if each[0].x < 0 or each[1].x < 0:
                continue

            max_x = max(max_x, each[0].x)
            max_x = max(max_x, each[1].x)

        base = next_base

    return max_x


def extend(p0, r0, p1, r1):
    d = linelen(p0, p1)
    a = (pow(r0, 2) - pow(r1, 2) + pow(d, 2)) / (2.0 * d)
    h = sqrt(pow(r0, 2) - pow(a, 2))

    p2 = Point(0, 0)
    p2.x = p0.x + a * (p1.x - p0.x) / d
    p2.y = p0.y + a * (p1.y - p0.y) / d

    p3 = Point(0, 0)
    p3.x = p2.x + h * (p1.y - p0.y) / d
    p3.y = p2.y - h * (p1.x - p0.x) / d

    p4 = Point(0, 0)
    p4.x = p2.x - h * (p1.y - p0.y) / d
    p4.y = p2.y + h * (p1.x - p0.x) / d

    opts = [p0, p1, p3, p4]
    opts.sort(key=lambda p: p.x, reverse=True)

    extension = [opts[0]]
    extension_b = [opts[0]]
    if opts[0] == p3 or opts[0] == p4:
        if p0.x > p1.x:
            extension.append(p0)
        else:
            extension.append(p1)

        if linelen(opts[0], p0) < linelen(opts[0], p1):
            extension_b.append(p0)
        else:
            extension_b.append(p1)

    else:
        if p3.x > p4.x:
            extension.append(p3)
        else:
            extension.append(p4)

        if linelen(opts[0], p3) < linelen(opts[0], p4):
            extension_b.append(p3)
        else:
            extension_b.append(p4)

    return [extension, extension[::-1], extension_b, extension_b[::-1]]


if __name__ == "__main__":
    pieces = list(map(int, input().split()))
    pieces = pieces[1:]
    pieces.sort()

    max_x = 0

    for each in permutations(pieces):
        max_x = max(max_x, solve(each))

    print(max_x)
