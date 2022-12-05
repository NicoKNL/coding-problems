import sys
import string

PRIO = ["."] + list(string.ascii_letters)


def solve(bags):
    sets = [set(b) for b in bags]

    overlap = sets[0]
    for s in sets:
        overlap = overlap.intersection(s)

    return PRIO.index(overlap.pop())


if __name__ == "__main__":
    sum_prio = 0

    lines = [l.strip() for l in list(sys.stdin)]

    for i in range(0, len(lines) - 2, 3):
        sum_prio += solve(lines[i : i + 3])

    print(sum_prio)
