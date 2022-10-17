from pprint import pprint


def is_solved(grid):
    for r in range(9):
        for c in range(9):
            if grid[r][c] == 0:
                return False

    return True


def print_grid(grid):
    for r in range(9):
        for c in range(9):
            if grid[r][c] == 0:
                grid[r][c] = "."
            else:
                grid[r][c] = str(grid[r][c])

    for line in grid:
        print(" ".join(line))


def row(grid, r):
    return grid[r]


def col(grid, c):
    return [grid[r][c] for r in range(9)]


def subgrid(grid, r, c):
    r_ = r // 3
    c_ = c // 3
    subgrid = []
    for row in range(r_ * 3, (r_ + 1) * 3):
        for col in range(c_ * 3, (c_ + 1) * 3):
            subgrid.append(grid[row][col])
    return subgrid


def both_other_rows(grid, r, c):
    r_ = r // 3
    other_rows = list(range(r_ * 3, (r_ + 1) * 3))
    other_rows.remove(r)

    ra = set(row(grid, other_rows[0]))
    rb = set(row(grid, other_rows[1]))

    return list(ra & rb)


def both_other_cols(grid, r, c):
    c_ = c // 3
    other_cols = list(range(c_ * 3, (c_ + 1) * 3))
    other_cols.remove(c)

    ca = set(col(grid, other_cols[0]))
    cb = set(col(grid, other_cols[1]))

    return list(ca & cb)


def space_count_subgrid_row(grid, r, c):
    c_ = c // 3
    subgrid_row = [grid[r][c__] for c__ in range(c_ * 3, (c_ + 1) * 3)]
    return subgrid_row.count(0)


def space_count_subgrid_col(grid, r, c):
    r_ = r // 3
    subgrid_col = [grid[r__][c] for r__ in range(r_ * 3, (r_ + 1) * 3)]
    return subgrid_col.count(0)


def solve(grid):
    # SPOTSOLVE SUBGRID
    for sr in range(0, 9, 3):
        for sc in range(0, 9, 3):
            sgrid = subgrid(grid, sr, sc)
            r_ = sr // 3
            c_ = sc // 3
            for i in range(1, 10):
                if i in sgrid:
                    continue
                opts = []
                for r in range(r_ * 3, (r_ + 1) * 3):
                    for c in range(c_ * 3, (c_ + 1) * 3):
                        if grid[r][c] != 0:
                            continue
                        if i not in row(grid, r) and i not in col(grid, c):
                            opts.append((r, c))

                if len(opts) == 1:
                    grid[opts[0][0]][opts[0][1]] = i
                    return True

    # SPOTSOLVE COL
    for c in range(9):
        for i in range(1, 10):
            opts = []
            if i in col(grid, c):
                continue

            for r in range(9):
                if grid[r][c]:
                    continue

                if i not in row(grid, r) and i not in subgrid(grid, r, c):
                    opts.append(r)

            if len(opts) == 1:
                grid[opts[0]][c] = i
                return True

    # SPOTSOLVE ROW
    for r in range(9):
        for i in range(1, 10):
            opts = []
            if i in row(grid, r):
                continue

            for c in range(9):
                if grid[r][c]:
                    continue

                if i not in col(grid, c) and i not in subgrid(grid, r, c):
                    opts.append(c)

            if len(opts) == 1:
                grid[r][opts[0]] = i
                return True

    for r in range(9):
        for c in range(9):
            if grid[r][c] != 0:
                continue

            opts = []
            for i in range(1, 10):
                if (
                    i not in row(grid, r)
                    and i not in col(grid, c)
                    and i not in subgrid(grid, r, c)
                ):
                    opts.append(i)

            if len(opts) == 1:
                grid[r][c] = opts[0]
                return True

    for r in range(9):
        for c in range(9):
            if grid[r][c] != 0:
                continue

            opts = []
            for i in range(1, 10):
                if (
                    i in both_other_rows(grid, r, c)
                    and i in both_other_cols(grid, r, c)
                    and i not in subgrid(grid, r, c)
                ):
                    opts.append(i)

            if len(opts) == 1:
                grid[r][c] = opts[0]
                return True

    for r in range(9):
        for c in range(9):
            if grid[r][c] != 0:
                continue

            opts = []
            for i in range(1, 10):
                if (
                    i in both_other_cols(grid, r, c)
                    and i not in subgrid(grid, r, c)
                    and space_count_subgrid_col(grid, r, c) == 1
                ):
                    opts.append(i)

            if len(opts) == 1:
                grid[r][c] = opts[0]
                return True

    for r in range(9):
        for c in range(9):
            if grid[r][c] != 0:
                continue

            opts = []
            for i in range(1, 10):
                if (
                    i in both_other_rows(grid, r, c)
                    and i not in subgrid(grid, r, c)
                    and space_count_subgrid_row(grid, r, c) == 1
                ):
                    opts.append(i)

            if len(opts) == 1:
                grid[r][c] = opts[0]
                return True

    return False


if __name__ == "__main__":
    grid = []

    for _ in range(9):
        grid.append(list(map(int, input().split())))

    while True:
        if not solve(grid):
            break

    if is_solved(grid):
        print("Easy")
        print_grid(grid)
    else:
        print("Not easy")
        print_grid(grid)
