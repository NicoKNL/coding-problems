def charToGrid(s: str) -> List[List[int]]:
    print(",", s,",")
    if s == " ":
        return [
            [0, 0, 0],
            [0, 0, 0],
            [0, 0, 0],
        ]
    elif s == "\\":
        return [
            [1, 0, 0],
            [0, 1, 0],
            [0, 0, 1],
        ]
    elif s == "/":
        return [
            [0, 0, 1],
            [0, 1, 0],
            [1, 0, 0],
        ]

def adjacent(GRID: List[List[int]], GROUPS: List[List[int]], row: int, col: int, n: int) -> List[Tuple[int, int]]:
    result = []
    for ro, co in [(0, 1),(0, -1), (-1, 0), (1, 0)]:
        if 0 <= row + ro < n and 0 <= col + co < n:
            if GROUPS[row + ro][col + co] == -1:
                if GRID[row + ro][col + co] == 0:
                    result.append((row + ro, col + co))
    return result

def flood(GRID: List[List[int]], GROUPS: List[List[int]], row: int, col: int, gid: int) -> None:
    Q = [(row, col)]
    i = 0
    GROUPS[row][col] = gid

    while i < len(Q):
        r, c = Q[i]
        i += 1

        for next_r, next_c in adjacent(GRID, GROUPS, r, c, len(GRID)):
            Q.append((next_r, next_c))
            GROUPS[next_r][next_c] = gid

class Solution:
    def regionsBySlashes(self, grid: List[str]) -> int:
        GRID = []
        for row in grid:
            r1, r2, r3 = [], [], []
            for col in row:
                subgrid = charToGrid(col)
                r1.extend(subgrid[0])
                r2.extend(subgrid[1])
                r3.extend(subgrid[2])

            GRID.append(r1)
            GRID.append(r2)
            GRID.append(r3)

        GROUPS = [[-1 for _ in range(len(GRID))] for __ in range(len(GRID))]
        gid = 0
        for r in range(len(GRID)):
            for c in range(len(GRID[r])):
                if GROUPS[r][c] == -1 and GRID[r][c] == 0:
                    flood(GRID, GROUPS, r, c, gid)
                    gid += 1

        return gid
