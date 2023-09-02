PRIMES = [2, 3, 5, 7, 11, 13, 17, 19, 23]


def solve(N):
    primes = []
    total = 1

    for i in range(N):
        target = 10**i
        for p in PRIMES:
            if total * p >= target:
                primes.append(p)
                total *= p
                break

    print(" ".join([str(p) for p in primes]))


if __name__ == "__main__":
    T = int(input())

    for _ in range(T):
        N = int(input())
        solve(N)
