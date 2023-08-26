import sys

MAP = {".": 0, "#": 1}
SIZE = 100
TIMESTEPS = 100


def adjacent(r, c):
    positions = []
    for ro in [-1, 0, 1]:
        for co in [-1, 0, 1]:
            if ro == 0 and co == 0:
                continue
            if r + ro < 0 or r + ro >= SIZE:
                continue
            if c + co < 0 or c + co >= SIZE:
                continue
            positions.append((r + ro, c + co))
    return positions


if __name__ == "__main__":
    lines = [l.strip() for l in sys.stdin]
    GRID = []
    for line in lines:
        GRID.append([MAP[c] for c in line])

    for _ in range(TIMESTEPS):
        NEXT_GRID = [[0 for _ in range(SIZE)] for __ in range(SIZE)]
        for r in range(SIZE):
            for c in range(SIZE):
                total = 0
                for ro, co in adjacent(r, c):
                    total += GRID[ro][co]

                if GRID[r][c]:
                    if total == 2 or total == 3:
                        NEXT_GRID[r][c] = 1
                else:
                    if total == 3:
                        NEXT_GRID[r][c] = 1

        GRID = NEXT_GRID

    total = 0
    for row in GRID:
        total += sum(row)
    print(total)
