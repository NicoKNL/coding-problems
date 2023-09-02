import sys


def parseInput(lines):
    segments = []
    for line in lines:
        line = line.split("->")
        print("line: ", line)

        for i in range(len(line) - 1):
            pt1 = tuple(map(int, line[i].split(",")))
            pt2 = tuple(map(int, line[i + 1].split(",")))
            segments.append((pt1, pt2))

    return segments


def canMoveDown(x, y):
    print("??? ", x, y)
    return GRID[y + 1][x] == "."


def canMoveDiagLeft(x, y):
    return GRID[y + 1][x - 1] == "."


def canMoveDiagRight(x, y):
    return GRID[y + 1][x + 1] == "."


if __name__ == "__main__":
    lines = [l.strip() for l in sys.stdin]

    segments = parseInput(lines)
    print(segments)

    GRID = [["." for _ in range(1000)] for __ in range(1000)]

    for ((x1, y1), (x2, y2)) in segments:
        if x1 > x2:
            x1, x2 = x2, x1

        if y1 > y2:
            y1, y2 = y2, y1

        if x1 == x2:
            for y in range(y1, y2 + 1):
                print("y", x1, y)
                GRID[y][x1] = "#"
        else:
            for x in range(x1, x2 + 1):
                print("x", x, y1)
                GRID[y1][x] = "#"

    while True:
        pos = [500, 0]

        moved = True
        while moved:
            if pos[1] >= 999:
                break

            moved = False

            if canMoveDown(*pos):
                pos[1] += 1
                moved = True
            elif canMoveDiagLeft(*pos):
                pos[0] -= 1
                pos[1] += 1
                moved = True
            elif canMoveDiagRight(*pos):
                pos[0] += 1
                pos[1] += 1
                moved = True
            else:
                GRID[pos[1]][pos[0]] = "o"

        if moved:
            break

    for row in GRID[:15]:
        print("".join(row[450:550]))

    print(sum([row.count("o") for row in GRID]))
