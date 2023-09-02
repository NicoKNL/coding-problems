import sys
import pickle
import json


def parseInput(lines):
    pairs = [[[2]], [[6]]]
    for line in lines:
        if line:
            pairs.append(json.loads(line))

    return pairs


def compare(p1, p2):
    result = -1
    for a, b in zip(p1, p2):
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

    signals = parseInput(lines)

    change = True
    while change:
        change = False
        for i in range(len(signals) - 1):
            if compare(signals[i], signals[i + 1]) == 1:
                signals[i], signals[i + 1] = signals[i + 1], signals[i]
                change = True
                break

    signals = signals[::-1]

    pos = []
    for i, s in enumerate(signals):
        if s == [[2]] or s == [[6]]:
            pos.append(i + 1)

    print(pos[0] * pos[1])
