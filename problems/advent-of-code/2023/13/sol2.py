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


def isFixable(row1: str, row2: str) -> bool:
    differences = 0

    for a, b in zip(row1, row2):
        if a != b:
            differences += 1

    return differences == 1


def reflects(grid: Grid, start: int) -> bool:
    lower = start
    upper = start + 1
    fixed_one = False

    while lower >= 0 and upper < len(grid):
        if grid[lower] != grid[upper]:
            if fixed_one:
                return False
            elif isFixable(grid[lower], grid[upper]):
                fixed_one = True
            else:
                return False

        lower -= 1
        upper += 1

    return fixed_one


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
