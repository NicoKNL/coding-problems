def solve(s):
    prefix = s[0]
    suffix = s[-1]

    longest = 0
    current = 0
    for c in s:
        if c == prefix or c == suffix:
            longest = max(longest, current)
            current = 0
        else:
            current += 1

    if longest == 0:
        print(-1)
    else:
        print(longest)


if __name__ == "__main__":
    T = int(input())

    for _ in range(T):
        s = input()
        solve(s)
