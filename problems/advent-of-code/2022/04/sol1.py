import sys

if __name__ == "__main__":
    lines = [l.strip() for l in sys.stdin]

    fully_contained = 0

    for line in lines:
        range1, range2 = line.split(",")
        range1 = list(map(int, range1.split("-")))
        range2 = list(map(int, range2.split("-")))

        len1 = range1[1] - range1[0]
        len2 = range2[1] - range2[0]

        if len1 < len2:
            range1, range2 = range2, range1

        if range1[0] <= range2[0] and range2[1] <= range1[1]:
            fully_contained += 1

    print(fully_contained)
