import sys
from collections import defaultdict

MAP = defaultdict(list)

if __name__ == "__main__":
    lines = [l.strip() for l in sys.stdin]
    lines = [l for l in lines if l]

    word = lines[-1]
    for line in lines[:-1]:
        s, t = line.split(" => ")
        MAP[s].append(t)

    molecules = set()
    for k in MAP.keys():
        for i in range(len(word) - len(k) + 1):
            if word[i : i + len(k)] == k:
                for v in MAP[k]:
                    molecules.add(word[:i] + v + word[i + len(k) :])

    print(len(molecules))
