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


def rotateGrid(grid: Grid) -> Grid:
    """Rotate 90 degrees CW"""
    grid = [list(row) for row in zip(*grid)]  # Transpose
    return [row[::-1] for row in grid]  # Reverse rows


def computeWeight(grid: Grid) -> int:
    total = 0
    for i, row in enumerate(reversed(grid), 1):
        total += i * row.count("O")
    return total


def stringify(grid: Grid) -> str:
    return "".join(["".join(row) for row in grid])


def cycle(grid: Grid) -> Grid:
    for _ in range(4):
        grid = tilt(grid)
        grid = rotateGrid(grid)
    return grid


def findCycle(grid: Grid) -> tuple[Grid, int, int]:
    GRIDS = dict()

    i = 1
    while True:
        grid = cycle(grid)
        hash = stringify(grid)

        if hash in GRIDS:
            cycle_length = i - GRIDS[hash]
            return (grid, i, cycle_length)
        else:
            GRIDS[hash] = i
            i += 1


def finishCycles(grid: Grid, spin_idx: int, cycle_length: int) -> Grid:
    spins_remaining = 1_000_000_000 - spin_idx
    full_cycles = spins_remaining // cycle_length
    spins_remaining -= full_cycles * cycle_length

    while spins_remaining:
        grid = cycle(grid)
        spins_remaining -= 1

    return grid


grid = [list(line.strip()) for line in sys.stdin]
ROWS = len(grid)
COLS = len(grid[0])

grid, spin_idx, cycle_length = findCycle(grid)
grid = finishCycles(grid, spin_idx, cycle_length)

print(computeWeight(grid))
