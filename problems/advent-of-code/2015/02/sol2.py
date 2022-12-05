import sys

if __name__ == "__main__":
    ribbon = 0

    for line in sys.stdin:
        dimensions = line.strip()

        l, w, h = map(int, dimensions.split("x"))

        dimensions = [l, w, h]
        dimensions.sort()
        ribbon += 2 * dimensions[0] + 2 * dimensions[1]
        ribbon += l * w * h

    print(ribbon)
