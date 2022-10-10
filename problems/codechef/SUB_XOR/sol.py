CACHE = [0]


def n_ones(n):
    return CACHE[n]


def contribution(s, i):
    subsequences = i + 1
    digit = int(s[i])

    if digit == 0:
        return 0
    else:  # 1
        if subsequences % 2 == 0:
            return 0
        else:
            return n_ones(len(s) - i)


def solve():
    n = int(input())
    s = input()

    result = -1

    for i in range(len(s)):
        if result == -1:
            result = contribution(s, i)
        else:
            result = result ^ contribution(s, i)

    print(result % 998244353)


def generate_cache():
    while len(CACHE) <= 100000:
        CACHE.append(CACHE[-1] * 2 + 1)


if __name__ == "__main__":
    T = int(input())

    generate_cache()

    for _ in range(T):
        solve()
