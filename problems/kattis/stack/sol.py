INFINITY = 1000000000000

DP = None
S = None


def solve(start, end):
    if DP[start][end] < INFINITY:
        return DP[start][end]

    DP[start][start] = 3
    LAST_SEEN = {
        S[start]: [start],
    }

    for k, letter in enumerate(S):
        if k < start + 1:
            continue

        if k > end:
            continue

        if letter in LAST_SEEN:
            if LAST_SEEN[letter][-1] == k - 1:
                DP[start][k] = DP[start][k - 1] + 1
                LAST_SEEN[letter].append(k)
                continue

        opt_a = DP[start][k - 1] + 3
        opt_b = INFINITY

        if letter in LAST_SEEN:
            opt_b = INFINITY
            for pos in LAST_SEEN[letter]:
                alternative = DP[start][pos]
                alternative += (
                    solve(
                        pos + 1,
                        k,
                    )
                    - 3
                    + 1
                )
                opt_b = min(opt_b, alternative)

        DP[start][k] = min(opt_a, opt_b)

        if letter in LAST_SEEN:
            LAST_SEEN[letter].append(k)
        else:
            LAST_SEEN[letter] = [k]

    return DP[start][end]


if __name__ == "__main__":
    n = int(input())

    for _ in range(n):
        S = input()
        DP = [[INFINITY for _ in range(len(S) + 1)] for __ in range(len(S) + 1)]
        solve(0, len(S))
        print(DP[0][len(S) - 1])
