from functools import reduce

if __name__ == "__main__":
    n = int(input())

    while len(str(n)) > 1:
        digits = map(int, list(str(n)))
        digits = [d for d in digits if d != 0]
        n = reduce(lambda x, y: x * y, digits)

    print(n)
