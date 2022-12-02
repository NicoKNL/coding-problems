import math


def nCr(n, r):
    f = math.factorial
    return f(n) // f(r) // f(n - r)


if __name__ == "__main__":
    T = int(input())

    for _ in range(T):
        n, k = map(int, input().split())
        print(nCr(n, k - 1))
