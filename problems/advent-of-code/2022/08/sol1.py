import sys

GRID = None
VISIBLE = None


def rotate90():
    global GRID
    global VISIBLE
    GRID = [list(t) for t in zip(*GRID)][::-1]
    VISIBLE = [list(t) for t in zip(*VISIBLE)][::-1]


def markVisibility():
    for r in range(len(GRID)):
        prev_height = -1
        for c, tree in enumerate(GRID[r]):
            if tree > prev_height:
                VISIBLE[r][c] = True
                prev_height = tree


if __name__ == "__main__":
    rows = [l.strip() for l in sys.stdin]
    GRID = [list(map(int, list(row))) for row in rows]

    VISIBLE = [[False for c in range(len(GRID[0]))] for r in range(len(GRID))]

    for _ in range(4):
        rotate90()
        markVisibility()

    print(sum([sum(row) for row in VISIBLE]))
