from math import gcd

if __name__ == "__main__":
    lo, hi = map(int, input().split())

    fizz = []
    buzz = []

    seq = input().split()

    for i, each in enumerate(seq):
        if "Fizz" in each:
            fizz.append(lo + i)
        if "Buzz" in each:
            buzz.append(lo + i)

    f = hi + 1
    b = hi + 1
    if fizz:
        f = fizz[0]
        for each in fizz[1:]:
            f = gcd(f, each)

    if buzz:
        b = buzz[0]
        for each in buzz[1:]:
            b = gcd(b, each)

    print(f, b)
