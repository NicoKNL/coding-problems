import sys
from itertools import permutations

PLACES = dict()


class Place:
    def __init__(self):
        self.adj = dict()


def parseLine(line):
    # A   to  B      =   DIST
    loc_a, _, loc_b, __, dist = line.split()
    dist = int(dist)

    if loc_a not in PLACES:
        PLACES[loc_a] = Place()

    if loc_b not in PLACES:
        PLACES[loc_b] = Place()

    PLACES[loc_a].adj[loc_b] = dist
    PLACES[loc_b].adj[loc_a] = dist


def travel(places):
    total = 0
    s = places[0]
    for t in places[1:]:
        total += PLACES[s].adj[t]
        s = t
    return total


if __name__ == "__main__":
    lines = [l.strip() for l in sys.stdin]

    for line in lines:
        parseLine(line)

    optimal = 10e9
    for ordering in permutations(PLACES.keys()):
        optimal = min(optimal, travel(ordering))

    print(optimal)
