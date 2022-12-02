def translate():
    num, source, target = input().split()

    source_nums = {}
    for i, c in enumerate(source):
        source_nums[c] = str(i)

    target_nums = {}
    for i, c in enumerate(target):
        target_nums[str(i)] = c

    source_value = 0
    source_base = len(source)
    for c in num:
        source_value += source_nums[c]

    v = int(source_value, source_base)
    # TODO: finish this


if __name__ == "__main__":
    T = int(input())

    for t in range(1, T + 1):
        print(f"Case #{t}: {translate()}")
