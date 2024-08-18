import sys
from itertools import product

Vec2 = tuple[int, int]

UP = (-1, 0)
DOWN = (1, 0)
LEFT = (0, -1)
RIGHT = (0, 1)

OFFSET = {
    "U": UP,
    "D": DOWN,
    "L": LEFT,
    "R": RIGHT,
}


def add(a: Vec2, b: Vec2) -> Vec2:
    return (a[0] + b[0], a[1] + b[1])


def parseInput() -> list[Vec2, int]:
    plan = []

    for line in sys.stdin:
        letter, steps, _ = line.split(" ")
        plan.append((OFFSET[letter], int(steps)))

    return plan


def getBorderPositions(plan: list[Vec2, int]) -> set[Vec2]:
    position = (0, 0)
    border = {position}

    for direction, steps in plan:
        for _ in range(steps):
            position = add(position, direction)
            border.add(position)

    return border


def initializeGrid(size: int) -> dict[Vec2, str]:
    grid = dict()

    for r, c in product(range(size), range(size)):
        grid[(r, c)] = "."

    return grid


def drawBorder(grid: dict[Vec2, str], border: set[Vec2], size: int) -> dict[Vec2, str]:
    for pos in border:
        pos = add(pos, (size // 2, size // 2))
        grid[pos] = "#"

    return grid


def countOutsideOfBorder(grid: dict[Vec2, str]) -> int:
    start = (0, 0)

    VISITED = {start}
    Q = [start]
    i = 0

    while i < len(Q):
        pos = Q[i]
        i += 1

        for offset in [UP, DOWN, LEFT, RIGHT]:
            next_pos = add(pos, offset)

            if next_pos in VISITED or next_pos not in grid or grid[next_pos] == "#":
                continue

            VISITED.add(next_pos)
            Q.append(next_pos)

    return len(VISITED)


plan = parseInput()
border = getBorderPositions(plan)

SIZE = 1000
GRID = initializeGrid(SIZE)
GRID = drawBorder(GRID, border, SIZE)

total = SIZE * SIZE
outside = countOutsideOfBorder(GRID)
print(total - outside)
