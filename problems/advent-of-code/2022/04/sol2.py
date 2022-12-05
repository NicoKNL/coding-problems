import sys

if __name__ == "__main__":
    lines = [l.strip() for l in sys.stdin]

    overlap = 0

    for line in lines:
        elf1, elf2 = line.split(",")
        elf1 = list(map(int, elf1.split("-")))
        elf2 = list(map(int, elf2.split("-")))

        r1 = elf1[1] - elf1[0]
        r2 = elf2[1] - elf2[0]

        if r1 < r2:
            elf1, elf2 = elf2, elf1

        if (
            (elf1[0] <= elf2[0] and elf2[0] <= elf1[1])
            or (elf1[0] <= elf2[1] and elf2[1] <= elf1[1])
            or (elf2[0] <= elf1[0] and elf1[0] <= elf2[1])
            or (elf2[0] <= elf1[1] and elf1[1] <= elf2[1])
        ):
            overlap += 1

    print(overlap)