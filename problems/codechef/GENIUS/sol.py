from math import ceil


def solve(n, target):
    score = 0

    correct = 0
    wrong = 0
    unattempted = 0

    if score < target:
        needed = ceil(target / 3)

        if needed <= n:
            correct += needed
            score += 3 * needed
            n -= needed

    if score > target:
        needed = score - target

        if needed <= n:
            wrong += needed
            score -= needed
            n -= needed

    unattempted = n

    if score == target:
        print("YES")
        print(f"{correct} {wrong} {unattempted}")
    else:
        print("NO")


if __name__ == "__main__":
    T = int(input())

    for _ in range(T):
        N, X = map(int, input().split())
        solve(N, X)
