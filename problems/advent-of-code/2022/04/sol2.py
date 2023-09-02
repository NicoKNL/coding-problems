import sys

if __name__ == "__main__":
    lines = [l.strip() for l in sys.stdin]

    fully_contained = 0

    for line in lines:
        range1, range2 = line.split(",")
        range1 = list(map(int, range1.split("-")))
        range2 = list(map(int, range2.split("-")))

        if range1[1] > range2[1]:
            range1, range2 = range2, range1

        if range1[1] >= range2[0]:
            fully_contained += 1

    print(fully_contained)
