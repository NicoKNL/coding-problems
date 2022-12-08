import sys

GRID = None
COUNT = None


def rotate90():
    global GRID
    global COUNT
    GRID = [list(t) for t in zip(*GRID)][::-1]
    COUNT = [list(t) for t in zip(*COUNT)][::-1]


def markVisibility():
    for r in range(len(GRID)):
        for c, tree in enumerate(GRID[r]):
            offset = 1
            while True:
                if c + offset >= len(GRID[r]):
                    COUNT[r][c] *= offset - 1
                    break

                if GRID[r][c + offset] >= tree:
                    COUNT[r][c] *= offset
                    break

                offset += 1


if __name__ == "__main__":
    rows = [l.strip() for l in sys.stdin]
    GRID = [list(map(int, list(row))) for row in rows]

    COUNT = [[1 for c in range(len(GRID[0]))] for r in range(len(GRID))]

    for _ in range(4):
        rotate90()
        markVisibility()

    print(max([max(row) for row in COUNT]))
