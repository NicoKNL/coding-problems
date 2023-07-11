from math import gcd


def solve():
    a, b, target = map(int, input().split())

    if target % gcd(a, b) == 0:
        print("Yes")
    else:
        print("No")


if __name__ == "__main__":
    N = int(input())

    for _ in range(N):
        solve()
