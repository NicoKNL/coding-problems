if __name__ == "__main__":
    l, n = map(int, input().split())

    rolls = 1

    missing = l % n
    while missing:
        rolls += 1

        n -= missing
        missing = l % n

    print(rolls)
