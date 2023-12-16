import sys
from copy import deepcopy

Grid = list[list[str]]


def createEmptyGrid(grid: Grid) -> Grid:
    empty_grid = deepcopy(grid)

    for r in range(ROWS):
        for c in range(COLS):
            if grid[r][c] == "O":
                empty_grid[r][c] = "."

    return empty_grid


def tilt(grid: Grid) -> Grid:
    new_grid = createEmptyGrid(grid)

    for r in range(ROWS):
        for c in range(COLS):
            if grid[r][c] == "O":
                row_up = r
                while row_up >= 0 and new_grid[row_up][c] == ".":
                    row_up -= 1
                new_grid[row_up + 1][c] = "O"

    return new_grid


def computeWeight(grid: Grid) -> int:
    total = 0
    for i, row in enumerate(reversed(grid), 1):
        total += i * row.count("O")
    return total


grid = [list(line.strip()) for line in sys.stdin]
ROWS = len(grid)
COLS = len(grid[0])

grid = tilt(grid)
print(computeWeight(grid))
