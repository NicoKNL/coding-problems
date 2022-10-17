if __name__ == "__main__":
    n, m = map(int, input().split())

    sneezes = 0
    while m > 0:
        if m & 1:
            sneezes += 1
        m = m // 2

    print(sneezes)
