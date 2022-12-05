import sys
import string

PRIO = ["."] + list(string.ascii_letters)

if __name__ == "__main__":
    sum_prio = 0

    for line in sys.stdin:
        line = line.strip()

        p1 = line[: len(line) // 2]
        p2 = line[len(line) // 2 :]

        s1 = set(p1)
        s2 = set(p2)

        overlap = s1.intersection(s2)
        sum_prio += PRIO.index(overlap.pop())

    print(sum_prio)
