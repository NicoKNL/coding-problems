import sys

if __name__ == "__main__":
    max_sum = 0
    sum = 0
    for line in sys.stdin:
        line = line.strip()

        if not line:
            sum = 0
        else:
            sum += int(line)

        max_sum = max(sum, max_sum)

    print(max_sum)
