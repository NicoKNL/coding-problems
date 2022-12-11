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

    DISPLAY = [[" " for _ in range(40)] for __ in range(6)]

    for i in range(240):
        scanline = i // 40
        center = i - scanline * 40
        if abs(SIGNAL[i + 1] - center) <= 1:
            DISPLAY[scanline][center] = "#"

    for scanline in DISPLAY:
        print("".join(scanline))
