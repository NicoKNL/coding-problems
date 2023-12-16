import sys

Grid = list[list[str]]


def asGrids(lines: list[str]) -> list[Grid]:
    grids = []
    grid = []
    for line in lines:
        if not line:
            grids.append(grid)
            grid = []
        else:
            grid.append(list(line))

    grids.append(grid)
    return grids


def transpose(grid: Grid) -> Grid:
    return [list(row) for row in zip(*grid)]


def reflects(grid: Grid, start: int) -> bool:
    lower = start
    upper = start + 1

    while lower >= 0 and upper < len(grid):
        if grid[lower] != grid[upper]:
            return False
        lower -= 1
        upper += 1

    return True


def findSplit(grid: Grid) -> int:
    for i in range(len(grid) - 1):
        if reflects(grid, i):
            return i + 1

    return 0


lines = [line.strip() for line in sys.stdin]
grids = asGrids(lines)

total = 0
for grid in grids:
    horizontal = findSplit(grid)
    vertical = findSplit(transpose(grid))

    total += 100 * horizontal
    total += vertical

print(total)
