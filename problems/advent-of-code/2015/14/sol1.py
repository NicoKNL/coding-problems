import sys


class Deer:
    def __init__(self, s):
        s = s.split()
        self.name = s[0]
        self.speed = int(s[3])
        self.stamina = int(s[6])
        self.rest = int(s[-2])

        self.moving = False
        self.t = 0
        self.distance = 0

    def advance(self):
        if self.t == 0:
            self.moving = not self.moving

            if self.moving:
                self.t = self.stamina
            else:
                self.t = self.rest

        if self.moving:
            self.distance += self.speed

        self.t -= 1


if __name__ == "__main__":
    lines = [l.strip() for l in sys.stdin]
    deer = [Deer(s) for s in lines]

    for _ in range(2503):
        for d in deer:
            d.advance()

    deer.sort(key=lambda d: d.distance, reverse=True)
    print(deer[0].distance)
