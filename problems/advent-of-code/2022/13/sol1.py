import sys
import pickle
import json


def parseInput(lines):
    pairs = []

    pair = []
    for line in lines:
        if not line:
            pairs.append(pair)
            pair = []
        else:
            pair.append(json.loads(line))

    if pair:
        pairs.append(pair)

    return pairs


def compare(p1, p2):
    print("p1: ", p1)
    print("p2: ", p2)
    result = -1
    for a, b in zip(p1, p2):
        print(f"- Compare {a} vs {b}")
        if type(a) == int and type(b) == int:
            if a < b:
                result = 1
            elif a > b:
                result = 0

        elif type(a) == list and type(b) == list:
            result = compare(a, b)

        elif type(a) == list:
            try:
                result = compare(a, list(b))
            except:
                result = compare(a, [b])

        else:
            try:
                result = compare(list(a), b)
            except:
                result = compare([a], b)

        if result != -1:
            break

    if result == -1 and len(p1) > len(p2):
        result = 0

    if result == -1 and len(p1) < len(p2):
        result = 1

    return result


if __name__ == "__main__":
    lines = [l.strip() for l in sys.stdin]

    pairs = parseInput(lines)

    ordered = 0
    for i, (p1, p2) in enumerate(pairs):
        print(f"== Pair {i + 1} ==")
        is_ordered = compare(p1, p2)
        if is_ordered:
            print("yes")
            ordered += i + 1

    print(ordered)
