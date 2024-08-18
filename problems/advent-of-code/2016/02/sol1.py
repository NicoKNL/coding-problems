import sys

instructions = [line.strip() for line in sys.stdin]

GRID = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9],
]


def applyMove(x, y, move):
    if move == "U" and y > 0:
        y -= 1
    elif move == "D" and y < 2:
        y += 1
    elif move == "L" and x > 0:
        x -= 1
    elif move == "R" and x < 2:
        x += 1

    return x, y


x = 1
y = 1

for instr in instructions:
    for move in instr:
        x, y = applyMove(x, y, move)

    print(GRID[y][x])
