import sys
from copy import deepcopy
from functools import cache

Pos = tuple[int, int]


def convertToGridDict(grid: list[str], size: int) -> dict[Pos, str]:
    size = len(grid)
    GRID = dict()
    OFFSETS = [-2, -1, 0, 1, 2]

    for r in range(len(grid)):
        for c in range(len(grid[0])):
            for ro in OFFSETS:
                for co in OFFSETS:
                    GRID[(r + ro * size, c + co * size)] = grid[r][c]
                    if GRID[(r + ro * size, c + co * size)] == "S":
                        GRID[(r + ro * size, c + co * size)] = "."

            if grid[r][c] == "S":
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


def quadraticPolynomial(u: int, v: int, w: int):
    a = w // 2 - v + u // 2
    b = v - u - w // 2 + v - u // 2
    c = u

    return lambda x: a * x**2 + b * x + c


lines = [line.strip() for line in sys.stdin]
SIZE = 131
GRID = convertToGridDict(lines, SIZE)

STEPS = 26501365
rings = STEPS // SIZE

steps_to_edge = (SIZE - 1) // 2
X = [steps_to_edge, steps_to_edge + SIZE, steps_to_edge + 2 * SIZE]
Y = []

x = 0
while len(Y) < len(X):
    if x in X:
        Y.append(countReachablePlots(GRID))

    GRID = step(GRID)
    x += 1


f = quadraticPolynomial(*Y)
print(f(rings))
