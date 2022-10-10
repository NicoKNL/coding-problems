SOLUTIONS = 0


# TODO: Use this function
def next_cell(grid, r, c):
    if c == len(grid[0]):
        return (r + 1, 0)

    return (r, c + 1)


def backtrack(grid, r, c, depth, max_depth):
    if depth == max_depth:
        global SOLUTIONS
        SOLUTIONS += 1

    if grid[r][c] != 0:
        if c == len(grid[0]):
            backtrack(grid, r + 1, 0, depth, max_depth)

    for i in range(10):
        if r == 0 or c == len(grid[0]):
            grid[r][c] = i
            backtrack(
                grid,
            )


def solve():
    nrows, ncols = map(int, input().split())

    grid = []
    missing = 0
    for r in range(nrows):
        row = []
        for c in range(ncols):
            v = int(input())
            row.append(v)

            if v == 0:
                missing += 1
        grid.append(row)

    backtrack(grid, 0, 0, 0, missing)

    print(SOLUTIONS)


if __name__ == "__main__":
    solve()
