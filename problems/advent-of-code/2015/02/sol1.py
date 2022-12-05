import sys

if __name__ == "__main__":
    paper = 0

    for line in sys.stdin:
        dimensions = line.strip()

        l, w, h = map(int, dimensions.split("x"))

        paper += 2 * l * w
        paper += 2 * w * h
        paper += 2 * h * l
        paper += min(l * w, w * h, h * l)

    print(paper)
