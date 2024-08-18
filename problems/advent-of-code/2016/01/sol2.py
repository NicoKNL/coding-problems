instructions = input().split(",")
instructions = [each.strip() for each in instructions]


class Vec2:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def rotateRight(self):
        x = self.x
        y = self.y
        self.x = y
        self.y = -x

    def rotateLeft(self):
        x = self.x
        y = self.y
        self.x = -y
        self.y = x


orientation = Vec2(0, 1)
position = Vec2(0, 0)
CACHE = set((0, 0))

for each in instructions:
    rotation = each[0]
    dist = int(each[1:])

    if rotation == "R":
        orientation.rotateRight()
    else:
        orientation.rotateLeft()

    for i in range(dist):
        position.x += orientation.x
        position.y += orientation.y

        if (position.x, position.y) in CACHE:
            print(abs(position.x) + abs(position.y))
            exit(0)
        else:
            CACHE.add((position.x, position.y))
