import sys
from heapq import heappop, heappush

Pos = tuple[int, int]
Dir = tuple[int, int]

# (row, column)
EAST: Dir = (0, 1)
SOUTH: Dir = (1, 0)


def add(position: Pos, direction: Dir) -> Pos:
    return (position[0] + direction[0], position[1] + direction[1])


def rotateLeft(direction: Dir) -> Dir:
    return (-direction[1], direction[0])


def rotateRight(direction: Dir) -> Dir:
    return (direction[1], -direction[0])


def isInGrid(row: int, col: int) -> bool:
    return 0 <= row < ROWS and 0 <= col < COLS


def getLineOfPositions(position: Pos, direction: Dir) -> list[Pos]:
    adjacent = []

    for _ in range(10):
        position = add(position, direction)
        if isInGrid(*position):
            adjacent.append(position)

    return adjacent


def getLineOfStates(
    position: Pos, direction: Dir, heat_loss: int
) -> list[tuple[int, Pos, Dir]]:
    neighbors = []

    for i, (r, c) in enumerate(getLineOfPositions(position, direction), 1):
        heat_loss += GRID[r][c]
        if i >= 4:
            neighbors.append((heat_loss, (r, c), direction))

    return neighbors


def getReachableStates(position: Pos, direction: Dir, heat_loss: int):
    states = []
    states.extend(getLineOfStates(position, rotateLeft(direction), heat_loss))
    states.extend(getLineOfStates(position, rotateRight(direction), heat_loss))
    return states


def dijkstraWithStraights() -> int:
    PQ = [(0, (0, 0), EAST), (0, (0, 0), SOUTH)]
    VISITED = set()

    while PQ:
        heat_loss, position, direction = heappop(PQ)

        if (position, direction) in VISITED:
            continue
        VISITED.add((position, direction))

        if position == TARGET:
            return heat_loss

        for state in getReachableStates(position, direction, heat_loss):
            heappush(PQ, state)


GRID = [list(map(int, list(line.strip()))) for line in sys.stdin]
ROWS = len(GRID)
COLS = len(GRID[0])
TARGET = (ROWS - 1, COLS - 1)

print(dijkstraWithStraights())
