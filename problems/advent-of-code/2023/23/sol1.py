import sys
from itertools import product

sys.setrecursionlimit(100000)

Pos = tuple[int, int]
DIRECTIONS = {
    "^": (-1, 0),
    ">": (0, 1),
    "v": (1, 0),
    "<": (0, -1),
}


def getNeighbors(pos: Pos) -> list[Pos]:
    neighbors = []

    offsets = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    for offset in offsets:
        neighbors.append((pos[0] + offset[0], pos[1] + offset[1]))

    return neighbors


def nextPosIsValid(pos: Pos, next_pos: Pos) -> bool:
    if next_pos not in GRID:
        # print("not in grid")
        return False

    if VISITED[next_pos]:
        # print("visited")
        return False

    if GRID[next_pos] == "#":
        # print("forest")
        return False

    if GRID[next_pos] in DIRECTIONS:
        # print("offset check")
        offset = (next_pos[0] - pos[0], next_pos[1] - pos[1])
        return offset == DIRECTIONS[GRID[next_pos]]

    return True


def dfsLongestPath(pos: Pos, depth: int) -> int:
    # print(">>>", pos, GRID[pos])
    if pos == (ROWS - 2, COLS - 2):
        global MAX_DEPTH
        MAX_DEPTH = max(MAX_DEPTH, depth + 1)
        return depth + 1

    max_depth = depth

    for next_pos in getNeighbors(pos):
        # print(next_pos, nextPosIsValid(pos, next_pos))
        if nextPosIsValid(pos, next_pos):
            VISITED[next_pos] = True
            max_depth = max(max_depth, dfsLongestPath(next_pos, depth + 1))
            VISITED[next_pos] = False

    return max_depth


lines = [list(line.strip()) for line in sys.stdin]
ROWS = len(lines)
COLS = len(lines[0])

GRID = dict()
VISITED = dict()
for r, c in product(range(ROWS), range(COLS)):
    GRID[(r, c)] = lines[r][c]
    VISITED[(r, c)] = False

MAX_DEPTH = 0
dfsLongestPath((0, 1), 0)

print(MAX_DEPTH)
