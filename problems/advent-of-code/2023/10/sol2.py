import sys
from collections import defaultdict

Pos = tuple[int, int]


def add(a: Pos, b: Pos) -> Pos:
    return (a[0] + b[0], a[1] + b[1])


# Directions: (row, col)
NORTH = (-1, 0)
EAST = (0, 1)
SOUTH = (1, 0)
WEST = (0, -1)

PIPES = {
    "|": [NORTH, SOUTH],
    "-": [EAST, WEST],
    "L": [NORTH, EAST],
    "J": [NORTH, WEST],
    "7": [SOUTH, WEST],
    "F": [SOUTH, EAST],
}

CONNECTIONS_TO_PIPE = {
    (NORTH, EAST): "L",
    (NORTH, WEST): "J",
    (NORTH, SOUTH): "|",
    (EAST, SOUTH): "F",
    (SOUTH, WEST): "7",
    (EAST, WEST): "-",
}


def parsePipes(grid: list[str]) -> dict[Pos, list[Pos]]:
    graph = defaultdict(list)

    for row in range(ROWS):
        for col in range(COLS):
            pipe = grid[row][col]
            current = (row, col)
            if pipe in PIPES:
                for offset in PIPES[pipe]:
                    next_pos = add(current, offset)
                    graph[current].append(next_pos)

    return graph


def getConnections(grid: list[str], pos: Pos) -> tuple[Pos]:
    connections = []

    north = add(pos, NORTH)
    east = add(pos, EAST)
    south = add(pos, SOUTH)
    west = add(pos, WEST)

    if grid[north[0]][north[1]] in ["|", "7", "F"]:
        connections.append(NORTH)

    if grid[east[0]][east[1]] in ["-", "7", "J"]:
        connections.append(EAST)

    if grid[south[0]][south[1]] in ["|", "L", "J"]:
        connections.append(SOUTH)

    if grid[west[0]][west[1]] in ["-", "F", "L"]:
        connections.append(WEST)

    return tuple(connections)


def findStart(grid: list[str]) -> Pos:
    for r in range(ROWS):
        for c in range(COLS):
            if grid[r][c] == "S":
                return (r, c)


def updateStartSymbol(grid: list[str], pos: Pos) -> list[str]:
    r, c = pos
    connections = getConnections(grid, pos)
    grid[r] = grid[r].replace("S", CONNECTIONS_TO_PIPE[connections])
    return grid


def travel(graph: dict[Pos, list[Pos]], start: Pos) -> set[Pos]:
    queue = [start]
    i = 0

    visited = {start}

    while i < len(queue):
        current = queue[i]

        for next_pos in graph[current]:
            if next_pos not in visited:
                visited.add(next_pos)
                queue.append(next_pos)

        i += 1

    return visited


def count(grid: list[str], edges: set[Pos]) -> set[Pos]:
    count = 0
    for r in range(ROWS):
        crossings = 0
        for c in range(COLS):
            if (r, c) in edges:
                if grid[r][c] in ["|", "L", "J"]:
                    crossings += 1
            else:
                if crossings % 2 == 1:
                    count += 1
    return count


grid = [line.strip() for line in sys.stdin]
ROWS = len(grid)
COLS = len(grid[0])

start = findStart(grid)
grid = updateStartSymbol(grid, start)
pipe_graph = parsePipes(grid)

visited = travel(pipe_graph, start)
inside_count = count(grid, visited)
print(inside_count)
