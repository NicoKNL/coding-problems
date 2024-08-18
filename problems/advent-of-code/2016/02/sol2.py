import sys

instructions = [line.strip() for line in sys.stdin]

GRID = [
    [0, 0, 1, 0, 0],
    [0, 2, 3, 4, 0],
    [5, 6, 7, 8, 9],
    [0, "A", "B", "C", 0],
    [0, 0, "D", 0, 0],
]


def dist(x, y):
    return abs(x - 2) + abs(y - 2)


def applyMove(x, y, move):
    if move == "U" and y > 0:
        if dist(x, y - 1) <= 2:
            y -= 1
    elif move == "D" and y < 4:
        if dist(x, y + 1) <= 2:
            y += 1
    elif move == "L" and x > 0:
        if dist(x - 1, y) <= 2:
            x -= 1
    elif move == "R" and x < 4:
        if dist(x + 1, y) <= 2:
            x += 1

    return x, y


x = 0
y = 2

for instr in instructions:
    for move in instr:
        x, y = applyMove(x, y, move)

    print(GRID[y][x])
