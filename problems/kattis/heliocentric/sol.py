from math import gcd


def solve(a, b):
    time_until_alignment = 0
    while a > 0 or b > 0:
        delta = 687 - b

        a = (a + delta) % 365
        b = (b + delta) % 687

        time_until_alignment += delta

    return time_until_alignment


if __name__ == "__main__":
    i = 1
    while True:
        try:
            a, b = map(int, input().split())
        except:
            break

        print(f"Case {i}: {solve(a, b)}")
        i += 1
