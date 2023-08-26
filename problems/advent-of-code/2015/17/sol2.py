import sys
from itertools import combinations

LITERS = 150

if __name__ == "__main__":
    lines = [l.strip() for l in sys.stdin]
    containers = [int(l) for l in lines]
    containers.sort()

    for k in range(1, len(containers)):
        count = 0
        for comb in combinations(containers, k):
            if sum(comb) == LITERS:
                count += 1

        if count > 0:
            print(count)
            break
