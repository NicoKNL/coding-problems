if __name__ == "__main__":
    n = int(input())

    CURRENT = 0
    MIN = 0

    for _ in range(n):
        CURRENT += int(input())
        MIN = min(MIN, CURRENT)

    print(abs(MIN))
