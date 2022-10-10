# f = [0] * (10 ** 6 + 1)
cache = []


def ncr(n, k):
    global cache
    k = min(k, n - k)

    if len(cache) == k + 1:
        return cache[k]

    result = 1

    for i in range(1, k + 1):
        result *= (n + 1 - i) / (i)

    cache.append(int(result))
    # print(k, cache)

    return cache[k]
    # return f[n] // f[r] // f[n - r]


def solve():
    global cache
    cache = [0]
    N, M = [int(x) for x in str(input()).split(" ")]

    fn = 1
    for i in range(1, N):
        fn += ncr(N, i)

    result = fn ** M
    result %= 10 ** 9 + 7

    print(result)


def solve2():
    N, M = [int(x) for x in str(input()).split(" ")]

    total_tuples = (2 ** M) ** N


if __name__ == "__main__":
    # for i in range(0, 10 ** 6 + 1):
    #     if i <= 1:
    #         f[i] = i
    #     else:
    #         f[i] = f[i - 1] * i
    T = int(input())

    while T:
        # solve()
        solve2()
        T -= 1