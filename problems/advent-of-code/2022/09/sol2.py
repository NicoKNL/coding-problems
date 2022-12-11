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

    ROPE = [(0, 0) for _ in range(10)]
    TAIL_POSITIONS = set()

    for direction, dist in moves:
        for _ in range(dist):
            offset = OFFSET[direction]
            OLD_ROPE = ROPE.copy()

            ROPE[0] = add(ROPE[0], offset)
            for i in range(1, len(ROPE)):
                if distance(ROPE[i - 1], ROPE[i]) > 1:
                    pull = subtract(ROPE[i - 1], ROPE[i])

                    if abs(pull[0]) > 1:
                        pull = (pull[0] // 2, pull[1])

                    if abs(pull[1]) > 1:
                        pull = (pull[0], pull[1] // 2)

                    ROPE[i] = add(ROPE[i], pull)

            TAIL_POSITIONS.add(ROPE[-1])

    print(len(TAIL_POSITIONS))
