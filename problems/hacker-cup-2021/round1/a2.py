CHARS_LEFT = "FX"
CHARS_RIGHT = "FO"
CHARS = ""


def swap():
    global CHARS

    if CHARS == CHARS_LEFT:
        CHARS = CHARS_RIGHT
    else:
        CHARS = CHARS_LEFT


def swap_count(s, start):
    global CHARS
    CHARS = start

    counter = []
    count = 0
    for c in s:
        if c not in CHARS:
            count += 1
            swap()

        counter.append(count)

    return counter


def solve():
    n = int(input())
    print("----")
    s = str(input())

    print(s)
    l_start = swap_count(s, CHARS_LEFT)
    r_start = swap_count(s, CHARS_RIGHT)
    print(l_start)
    print(r_start)

    for start in range(n):
        for end in range(start, n):
            print(start, end)

    return min(l_start, r_start)


if __name__ == "__main__":
    T = int(input())
    c = 1
    while T:
        print(f"Case #{c}: {solve()}")
        T -= 1
        c += 1
