import sys

if __name__ == "__main__":
    max_sum = 0
    cursum = 0
    sums = []
    for line in sys.stdin:
        line = line.strip()

        if not line:
            sums.append(cursum)
            cursum = 0
        else:
            cursum += int(line)

    if cursum:
        sums.append(cursum)

    sums.sort(reverse=True)

    print(sum(sums[:3]))
