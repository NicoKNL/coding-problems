from collections import defaultdict
from math import factorial

if __name__ == "__main__":
    while True:
        try:
            w = input()
        except:
            break

        count = factorial(len(w))

        M = defaultdict(int)
        for c in w:
            M[c] += 1

        for c_count in M.values():
            count //= factorial(c_count)

        print(count)
