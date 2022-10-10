I = None
TARGET = None
SUM = None


def recurse(count, depth, max_depth):
    global I
    global TARGET
    global SUM

    if I >= TARGET or depth >= max_depth:
        return

    SUM += count
    I += 1

    # Recurse left
    recurse(count, depth + 1, max_depth)

    # Recurse right
    recurse(count + 1, depth + 1, max_depth)


def solve(N, K):
    global I
    global TARGET
    global SUM

    I = 0
    TARGET = K
    SUM = 0

    recurse(1, 0, N)

    print(SUM)


if __name__ == "__main__":
    T = int(input())

    for _ in range(T):
        N, K = map(int, input().split())
        solve(N, K)
