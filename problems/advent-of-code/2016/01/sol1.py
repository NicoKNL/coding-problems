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

for each in instructions:
    rotation = each[0]
    dist = int(each[1:])

    if rotation == "R":
        orientation.rotateRight()
    else:
        orientation.rotateLeft()

    position.x += dist * orientation.x
    position.y += dist * orientation.y

print(abs(position.x) + abs(position.y))
