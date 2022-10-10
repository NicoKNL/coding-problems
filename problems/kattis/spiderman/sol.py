BEST = None
BEST_SEQ = ""


def recurse(D, i, n, height, max_height, seq):
    # print(f"{i:03}: [{height:03} {max_height:03}] {seq}")
    global BEST
    global BEST_SEQ

    if i == n and height == 0 and (max_height < BEST or BEST == -1):
        BEST = max_height
        BEST_SEQ = seq
        return

    if i == n:
        return

    if height - D[i] >= 0:
        recurse(D, i + 1, n, height - D[i], max_height, 2 * seq)

    if height + D[i] < BEST or BEST == -1:
        recurse(D, i + 1, n, height + D[i], max(max_height, height + D[i]), 2 * seq + 1)


def decode(seq):
    result = ""
    while seq:
        if seq % 2 == 1:
            result += "U"
        else:
            result += "D"

        seq = seq // 2

    return result[::-1]


def solve():
    global BEST
    global BEST_SEQ

    BEST = -1
    n = int(input())
    D = list(map(int, input().split()))

    if sum(D) % 2 == 1:
        print("IMPOSSIBLE")
        return

    recurse(D, 0, n, 0, 0, 0)

    if BEST == -1:
        print("IMPOSSIBLE")
    else:
        print(decode(BEST_SEQ))


if __name__ == "__main__":
    t = int(input())

    while t > 0:
        solve()
        t -= 1
