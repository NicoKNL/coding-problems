from collections import defaultdict

if __name__ == "__main__":
    PRESENTS = defaultdict(int)
    pos = [0, 0]
    PRESENTS[tuple(pos)] = 1

    moves = input()
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

    print(len(PRESENTS))
