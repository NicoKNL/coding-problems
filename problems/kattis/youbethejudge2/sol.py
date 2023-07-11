from collections import defaultdict


def onlyOneZero(grid):
    zeroes = 0
    for row in grid:
        zeroes += row.count(0)

    return zeroes == 1


def buildColorDict(n, grid):
    M = defaultdict(int)

    for row in grid:
        for cell in row:
            M[cell] += 1

    return M


def buildShapeDict(n, grid):
    M = defaultdict(list)

    for y, row in enumerate(grid):
        for x, cell in enumerate(row):
            M[cell].append((x, y))

    return M


def isCorner(cells):
    c0 = cells[0]
    c1 = cells[1]
    c2 = cells[2]
    X = 0
    Y = 1

    # OO
    # O.
    if (
        c0[X] == (c1[X] - 1)
        and c0[Y] == c1[Y]
        and c0[X] == c2[X]
        and c0[Y] == (c2[Y] - 1)
    ):
        return True

    # OO
    # .O
    if (
        c0[X] == (c1[X] - 1)
        and c0[Y] == c1[Y]
        and c1[X] == c2[X]
        and c1[Y] == (c2[Y] - 1)
    ):
        return True

    # .O
    # OO
    if (
        c1[X] == (c2[X] - 1)
        and c1[Y] == c2[Y]
        and c0[X] == c2[X]
        and c0[Y] == (c2[Y] - 1)
    ):
        return True

    # O.
    # OO
    if (
        c0[X] == c1[X]
        and c0[Y] == (c1[Y] - 1)
        and c1[X] == (c2[X] - 1)
        and c1[Y] == c2[Y]
    ):
        return True

    return False


if __name__ == "__main__":
    n = int(input())
    grid = []
    for i in range(2**n):
        grid.append(list(map(int, input().split())))

    M = buildColorDict(n, grid)

    oneZero = M[0] == 1

    allThree = True
    for i in range(1, ((4**n) - 1) // 3 + 1):
        if M[i] != 3:
            allThree = False
            break

    if oneZero and allThree:
        Mshape = buildShapeDict(n, grid)

        allCorner = True
        for i in range(1, ((4**n) - 1) // 3 + 1):
            if not isCorner(Mshape[i]):
                allCorner = False
                break

        if allCorner:
            print(1)
        else:
            print(0)
    else:
        print(0)
