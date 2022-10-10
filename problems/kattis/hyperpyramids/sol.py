SPLITS = []
FAC = [1, 1]


def recurse(split, dimension, remainder, last, D, H):
    if remainder == 0 and dimension == D:
        SPLITS.append(split.copy())
    elif remainder <= 0 or dimension >= D:
        return
    else:
        for i in range(last, remainder + 1):
            split[dimension] = i
            recurse(split, dimension + 1, remainder - i, i, D, H)
            split[dimension] = 0


def build_fac_map(H):
    for i in range(2, H + 1):
        FAC.append(FAC[i - 1] * i)


def factorial(split, H):
    result = FAC[H]

    for each in split:
        result /= FAC[each]

    return result


if __name__ == "__main__":
    D, H = map(int, input().split())

    split = [0] * D

    for i in range(H):
        split[0] = i
        recurse(split, 1, H - i - 1, i, D, H - 1)

    build_fac_map(H)
    nums = set()

    for s in SPLITS:
        nums.add(factorial(s, H - 1))

    for each in sorted(nums):
        print(int(each))
