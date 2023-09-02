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
    i = n - 1

    while i >= 0 and "#" not in GRID[i]:
        i -= 1

    while (n - (i + 1) - height) < 3:
        GRID.append(["." for _ in range(7)])
        n += 1

    return i


def collides(x, y):
    piece = PIECES[PIECE_INDEX]
    width = len(piece[0])
    height = len(piece)

    if x < 0 or x + (width - 1) > 6:
        return True

    if y - (height - 1) < 0:
        return True

    for yo in range(height):
        for xo in range(width):
            if piece[yo][xo] == "#":
                if GRID[y - yo][x + xo] == "#":
                    return True

    return False


def gasMove(x, y):
    global GAS
    try:
        direction = GAS[GAS_INDEX]
    except:
        GAS = 2 * GAS
        direction = GAS[GAS_INDEX]

    if direction == "<":
        if not collides(x - 1, y):
            return (x - 1, y)
    else:
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


if __name__ == "__main__":
    GAS = input().strip()
    print(len(GAS))
    GAS_INDEX = 0
    PIECE_COUNT = [0]
    from time import sleep

    for i in range(2022):
        y = extend()

        last = PIECE_COUNT[-1]
        while len(PIECE_COUNT) < y:
            PIECE_COUNT.append(last + 1)

        pos = (2, y + len(PIECES[PIECE_INDEX]) + 3)
        GRID[pos[1]][pos[0]] = "@"
        fixed = False
        GRID[pos[1]][pos[0]] = "."

        while not fixed:
            pos = gasMove(*pos)
            GAS_INDEX += 1
            fixed, pos = downMove(*pos)

            if fixed:
                fix(*pos)
                PIECE_INDEX = (PIECE_INDEX + 1) % 5
                break

    print(PIECE_COUNT[:100])
    period_found = False
    for start in range(1000):
        if period_found:
            break

        for period in range(10, 1000):
            a = GRID[start : start + period]
            b = GRID[start + period : start + 2 * period]
            c = GRID[start + 2 * period : start + 3 * period]
            if a == b and b == c:
                period_found = True
                break

    for i, row1 in enumerate(GRID[start + period : start + 2 * period]):
        row2 = GRID[start + 2 * period + i]
        row3 = GRID[start + 3 * period + i]
        row4 = GRID[start + 4 * period + i]
        r1 = "".join(row1)
        r2 = "".join(row2)
        r3 = "".join(row3)
        r4 = "".join(row4)
        print(r1, r2, r3, r4)

    print(start, period)
    target = 1000000000000  # - PIECE_COUNT[start]
    print(target)
    period_piece_count = PIECE_COUNT[2 * period] - PIECE_COUNT[period]
    print("ppc: ", period_piece_count)
    times = target // period_piece_count
    print("times: ", times)
    print(times * period)

    # 1514285714288
    # 2038461538433
