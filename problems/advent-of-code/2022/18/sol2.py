import sys
from collections import defaultdict
from itertools import product


class Vec3(object):
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def __add__(self, other):
        return Vec3(self.x + other.x, self.y + other.y, self.z + other.z)

    def __eq__(self, other):
        return hash(self) == hash(other)

    def __repr__(self):
        return str(self)

    def __str__(self):
        return f"({self.x}, {self.y}, {self.z})"

    def __hash__(self):
        return hash((self.x, self.y, self.z))


def parseInput():
    coords = []

    for line in sys.stdin:
        u = Vec3(*map(int, line.split(",")))
        u += Vec3(1, 1, 1)
        coords.append(u)

    return coords


def neighbours(u):
    offsets = product([-1, 0, 1], repeat=3)
    vlen = lambda v: abs(v[0]) + abs(v[1]) + abs(v[2])
    offsets = [Vec3(*o) for o in offsets if vlen(o) == 1]

    return [u + o for o in offsets]


def buildGraph():
    adj = defaultdict(set)

    for u in COORDS:
        adj[u] = set()
        for v in neighbours(u):
            if v in COORDS:
                adj[u].add(v)
                adj[v].add(u)

    return adj


def inBounds(u):
    if u.x < 0 or u.x > XMAX + 5:
        return False
    if u.y < 0 or u.y > YMAX + 5:
        return False
    if u.z < 0 or u.z > ZMAX + 5:
        return False
    return True


if __name__ == "__main__":
    COORDS = parseInput()
    ADJ = buildGraph()

    XMIN = min([c.x for c in COORDS])
    XMAX = max([c.x for c in COORDS])

    YMIN = min([c.x for c in COORDS])
    YMAX = max([c.x for c in COORDS])

    ZMIN = min([c.x for c in COORDS])
    ZMAX = max([c.x for c in COORDS])

    VISITED = [
        [[False for x in range(XMAX + 6)] for y in range(YMAX + 6)]
        for z in range(ZMAX + 6)
    ]
    print("--limits--")
    print(XMIN, XMAX)
    print(YMIN, YMAX)
    print(ZMIN, ZMAX)
    print("----------")
    OUTSIDE_COORDS = list()

    root = Vec3(0, 0, 0)
    VISITED[root.x][root.y][root.z]
    Q = [root]
    Qi = 0

    while Qi < len(Q):
        print("~~~~~~~~~~~~~~~~~")
        u = Q[Qi]
        print("visiting: ", u)
        for v in neighbours(u):
            if inBounds(v):
                print("    checking relevant neighbour: ", v)
                if not VISITED[v.x][v.y][v.z]:
                    if v in COORDS:
                        print("        seeing: ", v)
                        OUTSIDE_COORDS.append(v)
                    else:
                        VISITED[v.x][v.y][v.z] = True
                        Q.append(v)

        Qi += 1

    print(len(OUTSIDE_COORDS))
