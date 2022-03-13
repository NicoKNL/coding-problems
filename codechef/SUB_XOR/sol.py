CACHE = dict()


def string_to_num(s):
    result = 0

    for i in range(len(s)):
        if s[i] == "1":
            result += pow(2, len(s) - i - 1)

    return result


def all_substrings(s):
    for i in range(len(s)):
        for ii in range(i + 1, len(s) + 1):
            sub = s[i:ii]

            if sub not in CACHE:
                num = string_to_num(sub)
                CACHE[sub:30] = num

            yield CACHE[sub]


def solve():
    n = int(input())
    s = input()

    result = -1

    for each in all_substrings(s):
        if result == -1:
            result = each
        else:
            result = result ^ each

    print(result % 998244353)


if __name__ == "__main__":
    T = int(input())

    for _ in range(T):
        solve()
