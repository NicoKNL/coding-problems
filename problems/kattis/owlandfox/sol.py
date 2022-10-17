def sum_of_digits(n):
    s = map(int, list(str(n)))
    return sum(s)


def solve():
    n = int(input())

    target = sum_of_digits(n)
    while True:
        n = n - 1
        if sum_of_digits(n) == target - 1:
            break
    print(n)


if __name__ == "__main__":
    n = int(input())

    for _ in range(n):
        solve()
