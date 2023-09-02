from itertools import accumulate

MEMO = dict()
PRODUCTS = []
PRESUM = []


def round(n):
    diff = n % 10
    if diff < 5:
        return n - diff
    else:
        return n + (10 - diff)


def recurse(current, choose):
    # print(current, choose)
    # print(MEMO)
    if (current, choose) in MEMO:
        # print("MEMO")
        return MEMO[(current, choose)]

    if choose == 0:
        right = round(PRESUM[-1] - PRESUM[current])
        return right

    opt = 10e99
    for next_ in range(current + 1, len(PRODUCTS) - (choose - 1)):
        left = round(PRESUM[next_] - PRESUM[current])
        right = 0
        if (next_, choose - 1) in MEMO:
            # print("MEMO2")
            right = MEMO[(next_, choose - 1)]
        else:
            right = recurse(next_, choose - 1)
        opt = min(opt, left + right)

    MEMO[(current, choose)] = opt
    return opt


if __name__ == "__main__":
    N, D = map(int, input().split())
    PRODUCTS = list(map(int, input().split()))
    PRESUM = list(accumulate(PRODUCTS))

    opt = 10e99
    for i in range(len(PRODUCTS) - D):
        left = round(PRESUM[i])
        right = recurse(i, D - 1)
        opt = min(opt, left + right)
    print(opt)
