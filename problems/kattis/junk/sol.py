from math import sqrt
from enum import Enum


class COLLISION(Enum):
    NEVER = -1
    NO = 0
    YES = 1


class Sphere:
    def __init__(self, x, y, z, r, vx, vy, vz):
        self.x = float(x)
        self.y = float(y)
        self.z = float(z)
        self.r = float(r)
        self.vx = float(vx)
        self.vy = float(vy)
        self.vz = float(vz)
        self.is_stationary = False

        if vx == vy and vy == vz and vz == 0:
            self.is_stationary = True

        self.prev_dist = -1.0

    def collide(self, other):
        dx = self.x - other.x
        dy = self.y - other.y
        dz = self.z - other.z

        dist = sqrt(dx * dx + dy * dy + dz * dz)
        # print("pos: ", self.x, self.y, self.z, "   --   ", other.x, other.y, other.z)
        # print(
        #     "vel: ", self.vx, self.vy, self.vz, "   --   ", other.vx, other.vy, other.vz
        # )
        # print("dist: ", dist, self.r + other.r)

        if (self.r + other.r) >= dist:
            return COLLISION.YES
        elif self.prev_dist <= dist and self.prev_dist > 0:
            self.prev_dist = dist
            return COLLISION.NEVER
        else:
            self.prev_dist = dist
            return COLLISION.NO

    def advance(self, scalar):
        self.x += scalar * self.vx
        self.y += scalar * self.vy
        self.z += scalar * self.vz


def solve(a, b):
    # print("solving")
    t = 0.0
    STEP = 0.001
    # print(STEP)
    DIR = 1
    MIN_STEP = 0.000001
    while True:
        # print("t: ", t, STEP * DIR)
        state = a.collide(b)
        if state == COLLISION.YES:
            if t <= 0.0:
                print("No collision")
            else:
                print(f"{t:.3f}")
            return
        elif a.is_stationary and b.is_stationary:
            print("No collision")
            return
        elif state == COLLISION.NEVER:
            if t <= 0.0:
                print("No collision")
                return
            elif STEP < MIN_STEP:
                print(f"{t:.3f}")
                return
            else:
                # print("t: ", t)
                a.collide(b)
                DIR *= -1
                STEP /= 10
                # print(STEP * DIR)

        t += STEP * DIR
        a.advance(STEP * DIR)
        b.advance(STEP * DIR)


if __name__ == "__main__":
    T = int(input())

    for _ in range(T):
        a = Sphere(*map(int, input().split()))
        b = Sphere(*map(int, input().split()))
        solve(a, b)
