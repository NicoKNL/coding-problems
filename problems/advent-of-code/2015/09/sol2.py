import sys
from itertools import permutations

INF = 10e9
PLACES = dict()


class Place:
    def __init__(self):
        self.adj = dict()


def travel(places):
    total = 0
    s = places[0]
    for t in places[1:]:
        if t not in PLACES[s].adj:
            return INF
        total += PLACES[s].adj[t]
        s = t
    return total


if __name__ == "__main__":
    lines = [l.strip() for l in sys.stdin]

    for line in lines:
        data = line.split()
        s = data[0]
        t = data[2]
        dist = int(data[-1])

        if s not in PLACES:
            PLACES[s] = Place()

        if t not in PLACES:
            PLACES[t] = Place()

        PLACES[s].adj[t] = dist
        PLACES[t].adj[s] = dist

    optimal = 0
    for ordering in permutations(PLACES.keys()):
        optimal = max(optimal, travel(ordering))

    print(optimal)
