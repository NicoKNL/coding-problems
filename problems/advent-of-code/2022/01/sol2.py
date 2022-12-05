import sys

if __name__ == "__main__":
    lines = [line.strip() for line in sys.stdin]

    calories_per_elf = []
    current_sum = 0

    for line in lines:
        if not line:  # ''
            calories_per_elf.append(current_sum)
            current_sum = 0
        else:
            current_sum += int(line)

    if current_sum > 0:
        calories_per_elf.append(current_sum)

    calories_per_elf.sort(reverse=True)  # reverse -> Sort from LARGE to small
    print(sum(calories_per_elf[:3]))  # [:3] -> Take first three elements.
