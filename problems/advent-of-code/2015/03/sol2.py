from collections import defaultdict

PRESENTS = defaultdict(int)


def deliverPresents(moves):
    pos = [0, 0]
    PRESENTS[tuple(pos)] += 1

    for move in moves:
        if move == ">":
            pos[0] += 1
        if move == "<":
            pos[0] -= 1
        if move == "v":
            pos[1] -= 1
        if move == "^":
            pos[1] += 1

        PRESENTS[tuple(pos)] += 1


if __name__ == "__main__":
    moves = input()

    deliverPresents(moves[::2])
    deliverPresents(moves[1::2])

    print(len(PRESENTS))
