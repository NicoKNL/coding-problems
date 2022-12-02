def bfs(heads, tails):
    S = set((heads, tails))
    Q = [(heads, tails, 0)]
    qi = 0

    while qi < len(Q):
        h, t, d = Q[qi]
        qi += 1

        if (h, t) in S:
            continue
        else:
            S.add((h, t))

        if h == 2 and t == 0:
            return d + 1

        if t >= 1:
            Q.append((h, t + 1, d + 1))

        if t >= 2:
            Q.append((h + 1, t - 2, d + 1))

        if h >= 2:
            Q.append((h - 2, t, d + 1))

    return -1


def solve(heads, tails):
    print(bfs(heads, tails))


if __name__ == "__main__":
    while True:
        heads, tails = map(int, input().split())

        if heads == 0 and tails == 0:
            break

        solve(heads, tails)
