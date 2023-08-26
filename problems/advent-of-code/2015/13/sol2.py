import sys
from collections import defaultdict
from itertools import permutations

PEOPLE = defaultdict(dict)
INF = 10e9


def happiness(order):
    value = 0
    for i in range(len(order)):
        s = order[i % len(order)]
        t = order[(i + 1) % len(order)]
        value += PEOPLE[s][t]
        value += PEOPLE[t][s]
    return value


if __name__ == "__main__":
    lines = [l.strip() for l in sys.stdin]

    for line in lines:
        data = line.split()
        print(data)
        s = data[0]
        t = data[-1][:-1]

        plusminus = 1 if data[2] == "gain" else -1
        value = int(data[3]) * plusminus
        print(s, t, value)
        PEOPLE[s][t] = value

    for name in list(PEOPLE.keys()):
        PEOPLE["ME"][name] = 0
        PEOPLE[name]["ME"] = 0

    best = -INF
    for order in permutations(PEOPLE.keys()):
        best = max(best, happiness(order))
    print(best)
