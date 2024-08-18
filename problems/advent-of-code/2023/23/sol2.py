import sys
from itertools import product
from functools import cache

sys.setrecursionlimit(1000000)

Pos = tuple[int, int]
DIRECTIONS = {
    "^": (-1, 0),
    ">": (0, 1),
    "v": (1, 0),
    "<": (0, -1),
}

OFFSETS = DIRECTIONS.values()


def isIntersectionOrEndpoint(pos: Pos) -> bool:
    if GRID[pos] == "#":
        return False
    # print("intersection?: ", pos, GRID[pos])
    connections = 0

    for offset in OFFSETS:
        adj_pos = (pos[0] + offset[0], pos[1] + offset[1])
        if adj_pos in GRID and GRID[adj_pos] != "#":
            connections += 1
    return connections == 1 or connections > 2


@cache
def getNeighbors(pos: Pos) -> list[tuple[Pos, int]]:
    print("Got neighbors for: ", pos)
    neighbors = []

    Q = [(pos, 0)]
    visited = {pos}
    i = 0
    while i < len(Q):
        pos, dist = Q[i]
        i += 1

        for offset in OFFSETS:
            next_pos = (pos[0] + offset[0], pos[1] + offset[1])
            if next_pos in visited:
                continue
            visited.add(next_pos)

            if next_pos in GRID and isIntersectionOrEndpoint(next_pos):
                neighbors.append((next_pos, dist + 1))

            elif next_pos in GRID and GRID[next_pos] != "#":
                Q.append((next_pos, dist + 1))

    print("             Next: ", neighbors)
    return neighbors


def nextPosIsValid(pos: Pos, next_pos: Pos, depth: int) -> bool:
    if next_pos not in GRID:
        return False

    if VISITED[next_pos]:
        return False

    if GRID[next_pos] == "#":
        return False

    return True


def visualize():
    count = 0
    for r in range(ROWS):
        row = ""
        for c in range(COLS):
            if VISITED[(r, c)]:
                count += 1
                row += "O"
            else:
                row += GRID[(r, c)]
        print(row)
    print(count)


def dfsLongestPath(pos: Pos, depth: int) -> int:
    # print(">>> ", pos, depth)
    if pos == (ROWS - 1, COLS - 2):
        global MAX_DEPTH
        MAX_DEPTH = max(MAX_DEPTH, depth + 1)
        return depth + 1

    max_depth = 0
    for next_pos, next_dist in getNeighbors(pos):
        if VISITED[next_pos]:
            continue
        VISITED[next_pos] = True
        max_depth = max(max_depth, dfsLongestPath(next_pos, depth + next_dist))
        VISITED[next_pos] = False

    return max(depth, max_depth)


lines = [list(line.strip()) for line in sys.stdin]
ROWS = len(lines)
COLS = len(lines[0])

GRID = dict()
VISITED = dict()

for r, c in product(range(ROWS), range(COLS)):
    GRID[(r, c)] = lines[r][c]
    if GRID[(r, c)] != "#":
        GRID[(r, c)] = "."

    VISITED[(r, c)] = False

MAX_DEPTH = 0
dfsLongestPath((0, 1), 0)
print("max: ", MAX_DEPTH)
print(ROWS - 1, COLS - 2)
