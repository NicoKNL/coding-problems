def getDigitCount(n):
    test = 9
    count = 1

    while test < n:
        test *= 10
        test += 9
        count += 1

    return count


def resolve(a, b):
    digit_count_a = getDigitCount(a)
    digit_count_b = getDigitCount(b)

    diff = digit_count_a - digit_count_b
    if diff > 0: b *= pow(10, diff)

    if a >= b:
        tmp = a - b + 1
        digit_count_tmp = getDigitCount(tmp)

        if digit_count_tmp > diff:
            b *= 10
            diff += 1
        else:
            b += tmp

    return (diff, b)


def calculateSortingCost(v):
    cost = 0

    for i in range(1, len(v)):
        if v[i] <= v[i - 1]:
            fix_cost, fix = resolve(v[i - 1], v[i])
            cost += fix_cost
            v[i] = fix

    return cost


def solve():
    N = int(input())
    v = [int(x) for x in input().split()] 

    return calculateSortingCost(v)


if __name__ == "__main__":
    T = int(input())
    c = 1

    while T:
        print(f"Case #{c}: {solve()}")
        c += 1

