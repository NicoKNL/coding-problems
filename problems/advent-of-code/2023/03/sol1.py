import sys
from string import digits
from itertools import product

GRID = [list(line.strip()) for line in sys.stdin]
HEIGHT = len(GRID)
WIDTH = len(GRID[0])
IS_PART_NUMBER = [[False for _ in range(WIDTH)] for __ in range(HEIGHT)]


def isInBounds(row: int, col: int) -> bool:
    global HEIGHT, WIDTH
    return (0 <= row < HEIGHT) and (0 <= col < WIDTH)


def getAdjacentPositions(r: int, c: int) -> list[tuple[int, int]]:
    offset = [-1, 0, 1]
    adjacent_positions = []
    for row_offset, col_offset in product(offset, offset):
        if row_offset or col_offset:  # ignore [0, 0]
            adj_row = r + row_offset
            adj_col = c + col_offset

            if isInBounds(adj_row, adj_col):
                adjacent_positions.append((adj_row, adj_col))

    return adjacent_positions


def markPartNumbers(r: int, c: int) -> None:
    global GRID, IS_PART_NUMBER
    queue = [(r, c)]
    i = 0

    while i < len(queue):
        r, c = queue[i]
        if GRID[r][c] in digits:
            IS_PART_NUMBER[r][c] = True

        for adj_r, adj_c in getAdjacentPositions(r, c):
            if GRID[adj_r][adj_c] in digits and not IS_PART_NUMBER[adj_r][adj_c]:
                queue.append((adj_r, adj_c))

        i += 1


def extractPartNumbers():
    global GRID, IS_PART_NUMBER, HEIGHT, WIDTH

    numbers = []
    current_number = ""
    for r in range(HEIGHT):  # row
        for c in range(WIDTH):  # col
            if IS_PART_NUMBER[r][c]:
                current_number += GRID[r][c]
            elif current_number:
                numbers.append(int(current_number))
                current_number = ""

        if current_number:
            numbers.append(int(current_number))
            current_number = ""

    return numbers


part_numbers = []

for r in range(HEIGHT):  # row
    for c in range(WIDTH):  # column
        char = GRID[r][c]
        if char != "." and char not in digits:
            markPartNumbers(r, c)

part_numbers = extractPartNumbers()
print(sum(part_numbers))
