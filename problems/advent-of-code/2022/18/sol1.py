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
        coords.append(Vec3(*map(int, line.split(","))))

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


if __name__ == "__main__":
    COORDS = parseInput()
    ADJ = buildGraph()

    count = 0
    for u in ADJ:
        count += 6 - len(ADJ[u])

    print(count)

    # print(COORDS)
