import sys
from collections import defaultdict

PIECES = [
    [
        ["#", "#", "#", "#"],
    ],
    [
        [".", "#", "."],
        ["#", "#", "#"],
        [".", "#", "."],
    ],
    [
        [".", ".", "#"],
        [".", ".", "#"],
        ["#", "#", "#"],
    ],
    [
        ["#"],
        ["#"],
        ["#"],
        ["#"],
    ],
    [
        ["#", "#"],
        ["#", "#"],
    ],
]


PIECE_INDEX = 0
GRID = []
MAX_HEIGHT = 0


def extend():
    n = len(GRID)
    piece = PIECES[PIECE_INDEX]
    height = len(piece)
    print(n)
    i = n - 1

    while i >= 0 and "#" not in GRID[i]:
        i -= 1

    print(n, i, n - (i + 1))
    while (n - (i + 1) - height) < 3:
        print("extend")
        GRID.append(["." for _ in range(7)])
        n += 1

    return i


def collides(x, y):
    print("checking: ", x, y)
    piece = PIECES[PIECE_INDEX]
    width = len(piece[0])
    height = len(piece)

    if x < 0 or x + (width - 1) > 6:
        print("x collision limit")
        return True

    if y - (height - 1) < 0:
        print("y collision limit")
        return True

    for yo in range(height):
        for xo in range(width):
            if piece[yo][xo] == "#":
                if GRID[y - yo][x + xo] == "#":
                    print("intersect")
                    return True

    print("no collision")
    return False


def gasMove(x, y):
    global GAS
    try:
        direction = GAS[GAS_INDEX]
    except:
        GAS = 2 * GAS
        direction = GAS[GAS_INDEX]

    if direction == "<":
        print("< "),
        if not collides(x - 1, y):
            return (x - 1, y)
    else:
        print("> "),
        if not collides(x + 1, y):
            return (x + 1, y)

    return (x, y)


def downMove(x, y):
    if collides(x, y - 1):
        return True, (x, y)
    else:
        return False, (x, y - 1)


def fix(x, y):
    piece = PIECES[PIECE_INDEX]
    width = len(piece[0])
    height = len(piece)

    for yo in range(height):
        for xo in range(width):
            if piece[yo][xo] == "#":
                GRID[y - yo][x + xo] = "#"

    global MAX_HEIGHT
    MAX_HEIGHT = y + 1


def printGrid():
    if False:
        print()
        print()
        for row in reversed(GRID):
            print(f"|{''.join(row)}|")
        print("---------")


if __name__ == "__main__":
    GAS = input().strip()
    GAS_INDEX = 0
    from time import sleep

    for i in range(2022):
        print("=" * 80)
        # sleep(1)

        y = extend()
        pos = (2, y + len(PIECES[PIECE_INDEX]) + 3)
        GRID[pos[1]][pos[0]] = "@"
        fixed = False
        printGrid()
        GRID[pos[1]][pos[0]] = "."

        while not fixed:
            pos = gasMove(*pos)
            GAS_INDEX += 1
            fixed, pos = downMove(*pos)

            if fixed:
                print("fixed: ", pos)
                fix(*pos)
                PIECE_INDEX = (PIECE_INDEX + 1) % 5
                printGrid()
                break

    print(MAX_HEIGHT)
