import sys

if __name__ == "__main__":
    ops = [l.strip() for l in sys.stdin]

    SIGNAL = [1, 1]

    for op in ops:
        if op.startswith("noop"):
            SIGNAL.append(SIGNAL[-1])
        else:
            _, v = op.split()

            SIGNAL.append(SIGNAL[-1])
            SIGNAL.append(SIGNAL[-1] + int(v))

    POS = [20]
    while POS[-1] < 220:
        POS.append(POS[-1] + 40)

    print(sum([p * SIGNAL[p] for p in POS]))
