def sieve(n):
    prime = [True for _ in range(n + 1)]

    prime[0] = False
    prime[1] = False

    p = 2
    while p * p <= n:
        if prime[p]:
            i = p * p
            while i <= n:
                prime[i] = False
                i += p
        p += 1

    return prime


if __name__ == "__main__":
    P = int(input())
    is_prime = sieve(P)

    DP = [0 for _ in range(P + 1)]
    DP[2] = 1

    for p in range(3, P + 1):
        if is_prime[p]:
            ways = 0
            for i in range(14):
                n = p - (i + 1)

                if n < 2:
                    break

                if is_prime[n]:
                    ways += DP[n]

            DP[p] = ways

    print(DP[P])
