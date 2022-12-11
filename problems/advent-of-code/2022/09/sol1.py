import sys

OFFSET = {"L": (-1, 0), "R": (1, 0), "U": (0, 1), "D": (0, -1)}


def add(a, b):
    return (a[0] + b[0], a[1] + b[1])


def subtract(a, b):
    return (a[0] - b[0], a[1] - b[1])


def distance(a, b):
    return max(abs(a[0] - b[0]), abs(a[1] - b[1]))


if __name__ == "__main__":
    lines = [l.strip().split() for l in sys.stdin]
    moves = [(direction, int(distance)) for direction, distance in lines]

    TAIL = (0, 0)
    HEAD = (0, 0)

    TAIL_POSITIONS = set()

    for direction, dist in moves:
        offset = OFFSET[direction]

        for _ in range(dist):
            HEAD = add(HEAD, offset)

            if distance(HEAD, TAIL) > 1:
                TAIL = subtract(HEAD, offset)

            TAIL_POSITIONS.add(TAIL)

    print(len(TAIL_POSITIONS))
