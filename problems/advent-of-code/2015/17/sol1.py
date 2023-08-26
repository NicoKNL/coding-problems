import sys

LITERS = 150

if __name__ == "__main__":
    lines = [l.strip() for l in sys.stdin]
    containers = [int(l) for l in lines]
    containers.sort()

    TABLE = [[0 for _ in range(LITERS + 1)] for __ in range(len(containers))]

    for i, size in enumerate(containers):
        for volume in range(1, LITERS + 1):
            count = 0
            if volume == size:
                count += 1

            if i > 0 and volume - size >= 0:
                count += TABLE[i - 1][volume - size]

            TABLE[i][volume] = count

            if i > 0:
                TABLE[i][volume] += TABLE[i - 1][volume]

    print(TABLE[len(containers) - 1][LITERS])
