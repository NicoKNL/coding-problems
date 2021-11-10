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

    count = 0
    for c in s:
        if c not in CHARS:
            count += 1
            swap()

    return count


def solve():
    n = int(input())
    s = str(input())

    l_start = swap_count(s, CHARS_LEFT)
    r_start = swap_count(s, CHARS_RIGHT)

    return min(l_start, r_start)


if __name__ == "__main__":
    T = int(input())
    c = 1
    while T:
        print(f"Case #{c}: {solve()}")
        T -= 1
        c += 1
