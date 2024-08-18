GRID = []
for _ in range(6):
    GRID.append(list(input()))


def moveUp(x, y, z):
    return [x, -z, y]


def moveDown(x, y, z):
    return [x, z, -y]


def moveLeft(x, y, z):
    return [-z, y, x]


def moveRight(x, y, z):
    return [z, y, -x]


class Cube:
    def __init__(self):
        self.x = [1, 0, 0]  # +x
        self.y = [0, 1, 0]  # +y
        self.z = [0, 0, 1]  # +z

    def moveUp(self):
        self.x = moveUp(*self.x)
        self.y = moveUp(*self.y)
        self.z = moveUp(*self.z)

    def moveDown(self):
        self.x = moveDown(*self.x)
        self.y = moveDown(*self.y)
        self.z = moveDown(*self.z)

    def moveLeft(self):
        self.x = moveLeft(*self.x)
        self.y = moveLeft(*self.y)
        self.z = moveLeft(*self.z)

    def moveRight(self):
        self.x = moveRight(*self.x)
        self.y = moveRight(*self.y)
        self.z = moveRight(*self.z)

    def getFront(self):
        if self.x[2] == -1:
            return "+x"
        if self.x[2] == 1:
            return "-x"
        if self.y[2] == -1:
            return "+y"
        if self.y[2] == 1:
            return "-y"
        if self.z[2] == -1:
            return "+z"
        if self.z[2] == 1:
            return "-z"


CUBE = Cube()
FACES = set()


def inBounds(r, c):
    return 0 <= r and r < 6 and 0 <= c and c < 6


def canFold(r, c):
    front = CUBE.getFront()
    if GRID[r][c] == front:
        return True
    elif GRID[r][c] != "#" and GRID[r][c] != ".":
        return False
    elif front in FACES:
        return False
    GRID[r][c] = front
    FACES.add(front)
    # else: GRID[r][c] == "#"
    # We traverse and recurse
    left = [r, c - 1]
    right = [r, c + 1]
    up = [r - 1, c]
    down = [r + 1, c]

    valid = True
    for i, pos in enumerate([left, right, up, down]):
        if inBounds(*pos) and GRID[pos[0]][pos[1]] == "#":
            if i == 0:
                CUBE.moveLeft()
            if i == 1:
                CUBE.moveRight()
            if i == 2:
                CUBE.moveUp()
            if i == 3:
                CUBE.moveDown()
            valid = canFold(*pos)
            if i == 0:
                CUBE.moveRight()
            if i == 1:
                CUBE.moveLeft()
            if i == 2:
                CUBE.moveDown()
            if i == 3:
                CUBE.moveUp()

        if not valid:
            return False

    return True


for r in range(6):
    for c in range(6):
        if GRID[r][c] == "#":
            if canFold(r, c):
                print("can fold")
            else:
                print("cannot fold")

            # for row in GRID:
            #     print(row)
            exit(0)
