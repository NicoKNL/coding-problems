from math import sqrt


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


IS_PRIME = sieve(20000)


def solve():
    n, max_dist = map(int, input().split())
    flowers = []
    for i in range(n):
        u, v = map(int, input().split())
        flowers.append((u, v))

    x, y = (0, 0)
    dist = 0
    answer = 0

    for i, (u, v) in enumerate(flowers, 1):
        next_dist = sqrt((u - x) * (u - x) + (v - y) * (v - y))

        if dist + next_dist > max_dist:
            break

        dist += next_dist
        x, y = u, v

        if IS_PRIME[i]:
            answer = i

    print(answer)


T = int(input())

for _ in range(T):
    solve()
