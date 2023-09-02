import sys
from itertools import combinations
from functools import reduce
from operator import mul

INF = 1e99

if __name__ == "__main__":
    packages = [int(l.strip()) for l in sys.stdin]
    packages.sort(reverse=True)
    print(packages)

    TARGET = sum(packages) // 3
    print(TARGET)

    QE = INF
    for k in range(len(packages)):
        if QE < INF:
            break

        for comb in combinations(packages, k):
            if sum(comb) == TARGET:
                QE = min(QE, reduce(mul, comb, 1))

    print(QE)
