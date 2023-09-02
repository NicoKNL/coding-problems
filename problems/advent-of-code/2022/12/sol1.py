import sys
import string


def isInBounds(r, c):
    if r < 0 or r >= ROWS:
        return False

    if c < 0 or c >= COLS:
        return False

    return True


def canTravel(r1, c1, r2, c2):
    if not isInBounds(r2, c2):
        return False

    return GRID[r1][c1] + 1 >= GRID[r2][c2]


def adj(r, c):
    OFFSETS = [(0, 1), (0, -1), (1, 0), (-1, 0)]

    adj = []

    for o in OFFSETS:
        pos = (r + o[0], c + o[1])

        if canTravel(r, c, *pos):
            adj.append(pos)
    print("adj: ", adj)
    return adj


if __name__ == "__main__":
    lines = [l.strip() for l in sys.stdin]
    GRID = [list(l) for l in lines]
    ROWS = len(GRID)
    COLS = len(GRID[0])
    INF = 10e9

    START = END = (0, 0)
    for r, row in enumerate(GRID):
        for c, height in enumerate(row):
            if height == "S":
                START = (r, c)
                GRID[r][c] = 0
            elif height == "E":
                END = (r, c)
                GRID[r][c] = 25
            else:
                GRID[r][c] = string.ascii_lowercase.index(GRID[r][c])
        print(row)

    DIST = [[INF for _ in range(COLS)] for __ in range(ROWS)]

    DIST[START[0]][START[1]] = 0
    Q = [(START, 0)]
    Qi = 0

    while Qi < len(Q):
        (r1, c1), dist = Q[Qi]
        print(r1, c1, dist)

        for (r2, c2) in adj(r1, c1):
            print(r2, c2)
            if dist + 1 < DIST[r2][c2]:
                DIST[r2][c2] = dist + 1
                Q.append(((r2, c2), dist + 1))
        Qi += 1

    print(DIST[END[0]][END[1]])
