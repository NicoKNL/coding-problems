def grid(A, B, ai, bi):
    grid = [["." for _ in range(len(A))] for _ in range(len(B))]

    grid[bi] = list(A)

    for i, row in enumerate(grid):
        grid[i][ai] = B[i]

    for row in grid:
        print("".join(row))


if __name__ == "__main__":
    A, B = input().split()

    for i, a in enumerate(A):
        for ii, b in enumerate(B):
            if a == b:
                grid(A, B, i, ii)
                exit(0)
