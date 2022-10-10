from functools import reduce


def solve():
    pass1 = input()
    pass2 = input()

    options = [1 if a == b else 2 for a, b in zip(pass1, pass2)]

    mul = lambda x, y: x * y
    total = reduce(mul, options)
    print(total)


if __name__ == "__main__":
    solve()
