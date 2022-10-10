from math import gcd

if __name__ == "__main__":
    n = int(input())

    for _ in range(n):
        a, b = map(int, input().split())
        print(f"{gcd(a, b)} {a * b // gcd(a, b)}")
