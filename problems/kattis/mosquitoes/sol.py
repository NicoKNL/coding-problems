# Circle chord solution
from math import sqrt, atan2, sin, cos


def avg(p1, p2):
    x = p1[0] + p2[0]
    y = p1[1] + p2[1]
    return (x / 2.0, y / 2.0)


def dist(p1, p2):
    dx = p1[0] - p2[0]
    dy = p1[1] - p2[1]
    return sqrt(dx * dx + dy * dy)


def rot90_2D(vec):
    return (vec[1], -vec[0])


def getCenterFromChordAndRadius(p1, p2, radius):
    chord_center = avg(p1, p2)

    if dist(p1, p2) > radius:
        return chord_center

    halfchord_len = dist(p1, chord_center)

    offset_from_circle_center = sqrt(radius * radius - halfchord_len * halfchord_len)

    dirvec = (chord_center[0] - p1[0], chord_center[1] - p1[1])

    # TODO: For some reason this vector offset approach also errors in 1 specific subcase in the last testcase set...
    # dirvec = rot90_2D(dirvec)
    # dirvec_len = sqrt(dirvec[0] * dirvec[0] + dirvec[1] * dirvec[1])
    # dirvec = (dirvec[0] / dirvec_len, dirvec[1] / dirvec_len)

    # center_x = chord_center[0] + offset_from_circle_center * dirvec[0]
    # center_y = chord_center[1] + offset_from_circle_center * dirvec[1]

    angle = atan2(dirvec[0], dirvec[1])

    center_x = chord_center[0] + offset_from_circle_center * cos(angle)
    center_y = chord_center[1] + offset_from_circle_center * sin(angle)

    return (center_x, center_y)


def solve():
    inp = input().split()
    if not inp:
        inp = input().split()

    n = int(inp[0])
    r = float(inp[1]) / 2.0

    points = []

    for _ in range(n):
        x, y = map(float, input().split())
        points.append((x, y))

    answer = 1
    for u in range(n):
        for v in range(n):
            if u == v:
                continue
            center = getCenterFromChordAndRadius(points[u], points[v], r)

            count = 0
            for k in range(n):
                if dist(center, points[k]) <= r:
                    count += 1

            answer = max(answer, count)

    print(answer)


if __name__ == "__main__":
    cases = int(input())

    for _ in range(cases):
        solve()
