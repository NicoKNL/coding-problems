import sys
from copy import deepcopy

Pos = tuple[int, int]


def convertToGridDict(grid: list[str]) -> dict[Pos, str]:
    GRID = dict()

    for r in range(len(grid)):
        for c in range(len(grid[0])):
            GRID[(r, c)] = grid[r][c]
            if GRID[(r, c)] == "S":
                GRID[(r, c)] = "O"
    return GRID


def getNeighbors(pos: Pos) -> list[Pos]:
    neighbors = []

    offsets = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    for offset in offsets:
        neighbors.append((pos[0] + offset[0], pos[1] + offset[1]))

    return neighbors


def step(grid: dict[Pos, str]) -> dict[Pos, str]:
    reachable_positions = set()

    for pos, plot in grid.items():
        if plot != "O":
            continue

        grid[pos] = "."
        for next_pos in getNeighbors(pos):
            if next_pos in grid and grid[next_pos] != "#":
                reachable_positions.add(next_pos)

    for pos in reachable_positions:
        grid[pos] = "O"

    return grid


def countReachablePlots(grid: dict[Pos, str]) -> int:
    return sum(plot == "O" for plot in grid.values())


lines = [line.strip() for line in sys.stdin]
GRID = convertToGridDict(lines)

for _ in range(64):
    GRID = step(GRID)

plot_count = countReachablePlots(GRID)
print(plot_count)
