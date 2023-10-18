from itertools import permutations

ROWS, COLS = map(int, input().split())

GRID = [[0 for _ in range(COLS)] for __ in range(ROWS)]
SEATED = [[False for _ in range(COLS)] for __ in range(ROWS)]

POS = [-1, -1, 0, 1, 1]
OFFSETS = list(set(permutations(POS, 2)))

N = int(input())
for _ in range(N):
    r, c = map(int, input().split())
    r -= 1
    c -= 1

    SEATED[r][c] = True

    for ro, co in OFFSETS:
        u = r + ro
        v = c + co

        if 0 <= u and u < ROWS:
            if 0 <= v and v < COLS:
                GRID[u][v] += 1


result = [0 for _ in range(9)]

for r in range(ROWS):
    for c in range(COLS):
        if SEATED[r][c]:
            count = GRID[r][c]
            result[count] += 1

print(" ".join(map(str, result)))
