import sys
from collections import defaultdict

MAP = dict()

if __name__ == "__main__":
    lines = [l.strip() for l in sys.stdin]
    lines = [l for l in lines if l]

    WORD = lines[-1]
    values = []
    for line in lines[:-1]:
        s, t = line.split(" => ")
        values.append(t)
        MAP[t] = s

    values.sort(key=lambda x: len(x))
    steps = 0
    while WORD != "e":
        print(WORD)
        for v in values:
            if v in WORD:
                steps += 1
                WORD = WORD.replace(v, MAP[v])
    print(steps)
    exit(0)
    queue = [("e", 0)]
    qi = 0
    best = 10e9
    while qi < len(queue):
        word, depth = queue[qi]
        print(depth, word)
        qi += 1

        if word in MEMO and MEMO[word] <= depth:
            continue
        else:
            MEMO[word] = depth

        if len(word) > len(WORD):
            continue
        elif len(word) == len(WORD) and word == WORD:
            best = min(depth, best)
            continue

        for k in MAP.keys():
            for i in range(len(word) - len(k) + 1):
                if word[i : i + len(k)] == k:
                    for v in MAP[k]:
                        queue.append((word[:i] + v + word[i + len(k) :], depth + 1))

    print(best)
