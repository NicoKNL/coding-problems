from random import shuffle


class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y


class Rectangle:
    def __init__(self, width, height, x, y):
        self.width = width
        self.height = height
        self.area = width * height
        self.top_left = Point(x, y)
        self.bottom_right = Point(x + width, y + height)
        self.overlaps = 0

    def intersects(self, other):
        return max(self.top_left.x, other.top_left.x) < min(
            self.bottom_right.x, other.bottom_right.x
        ) and max(self.top_left.y, other.top_left.y) < min(
            self.bottom_right.y, other.bottom_right.y
        )


def recurse(rectangles, picks, cur, area):
    if cur >= len(rectangles):
        return area
        # print("picks: ", picks)
        return sum(r.area for i, r in enumerate(rectangles) if picks[i])

    global potential
    global ans
    if area + potential[cur] < ans:
        return 0

    if picks[cur]:
        # print(cur, "checking...")
        r1 = rectangles[cur]
        for i in range(cur):
            if picks[i]:
                if r1.intersects(rectangles[i]):
                    return 0

    a = recurse(rectangles, picks, cur + 1, area)

    picks[cur + 1] = True
    if cur == len(rectangles) - 1:
        b = recurse(rectangles, picks, cur + 1, area)
    else:
        b = recurse(rectangles, picks, cur + 1, area + rectangles[cur + 1].area)
    picks[cur + 1] = False

    return max(a, b)


def solve(N):
    rectangles = []

    for _ in range(N):
        data = map(int, input().split())
        rectangles.append(Rectangle(*data))

    for i in range(len(rectangles)):
        r1 = rectangles[i]
        for ii in range(i, len(rectangles)):
            r2 = rectangles[ii]
            if r1.intersects(r2):
                r1.overlaps += 1
                r2.overlaps += 1

    rectangles.sort(
        key=lambda r: (r.overlaps, r.area, r.top_left.x, r.top_left.y), reverse=True
    )

    picks = [False] * (len(rectangles) + 1)

    global potential
    potential = [r.area for r in rectangles]
    potential.reverse()
    for i in range(1, len(potential)):
        potential[i] += potential[i - 1]
    potential.reverse()
    # print(potential)

    global ans
    ans = 0
    for i in range(N):
        if potential[i] < ans:
            break
        picks[i] = True
        ans = max(ans, recurse(rectangles, picks, i, rectangles[i].area))
        picks[i] = False

    print(ans)


if __name__ == "__main__":
    while True:
        N = int(input())

        if N == 0:
            break

        solve(N)
