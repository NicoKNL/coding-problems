import sys
from string import digits
from itertools import product
from collections import defaultdict

GRID = [list(line.strip()) for line in sys.stdin]
HEIGHT = len(GRID)
WIDTH = len(GRID[0])
GEAR_IDS = [[0 for _ in range(WIDTH)] for __ in range(HEIGHT)]
ID = 1


def isInBounds(r: int, c: int):
    global HEIGHT, WIDTH
    return (0 <= r < HEIGHT) and (0 <= c < WIDTH)


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
    global GRID, GEAR_IDS, ID
    queue = [(r, c)]
    i = 0

    while i < len(queue):
        r, c = queue[i]
        if GRID[r][c] in digits:
            GEAR_IDS[r][c] = ID

        for adj_r, adj_c in getAdjacentPositions(r, c):
            if GRID[adj_r][adj_c] in digits and not GEAR_IDS[adj_r][adj_c]:
                queue.append((adj_r, adj_c))

        i += 1


def extractPossibleGears() -> dict[int, list[int]]:
    global GRID, GEAR_IDS, HEIGHT, WIDTH

    possible_gears = defaultdict(list)
    current_number = ""
    id = -1
    for r in range(HEIGHT):  # row
        for c in range(WIDTH):  # col
            if GEAR_IDS[r][c]:
                id = GEAR_IDS[r][c]
                current_number += GRID[r][c]
            elif current_number:
                possible_gears[id].append(int(current_number))
                id = -1
                current_number = ""

        if current_number:
            possible_gears[id].append(int(current_number))
            id = -1
            current_number = ""

    return possible_gears


def extractRealGears(possible_gears: dict[int, list[int]]) -> list[tuple[int, int]]:
    gears = []

    for part_numbers in possible_gears.values():
        if len(part_numbers) == 2:
            gears.append(tuple(part_numbers))

    return gears


for r in range(HEIGHT):  # row
    for c in range(WIDTH):  # column
        char = GRID[r][c]
        if char == "*":
            markPartNumbers(r, c)
            ID += 1

possible_gears = extractPossibleGears()
gears = extractRealGears(possible_gears)

gear_ratios = [gear[0] * gear[1] for gear in gears]
print(sum(gear_ratios))
