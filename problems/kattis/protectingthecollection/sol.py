LEFT = complex(0, -1)
RIGHT = complex(0, 1)
DOWN = complex(1, 0)
UP = complex(-1, 0)

N, COL, ROW = map(int, input().split())

GRID = dict()
for r in range(N):
    row = input().split(" ")
    for c in range(N):
        GRID[complex(r, c)] = row[c]


def rotateLeft(v):
    return complex(-v.imag, v.real)


def rotateRight(v):
    return rotateLeft(rotateLeft(rotateLeft(v)))


def cast(pos, direction):
    positions = set()
    if GRID[pos] == ".":
        positions.add(pos)

    while True:
        pos += direction
        if pos not in GRID:
            break

        if GRID[pos] == ".":
            positions.add(pos)

        if GRID[pos] == "\\":
            if direction in [LEFT, RIGHT]:
                direction = rotateRight(direction)
            else:
                direction = rotateLeft(direction)
        elif GRID[pos] == "/":
            if direction in [LEFT, RIGHT]:
                direction = rotateLeft(direction)
            else:
                direction = rotateRight(direction)

    return positions


front_cast = cast(complex(0, COL - 1), complex(1, 0))
back_cast = cast(complex(ROW - 1, N - 1), complex(0, -1))
if front_cast & back_cast:
    print("YES")
else:
    print("NO")
