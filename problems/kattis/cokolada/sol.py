if __name__ == "__main__":
    N = int(input())

    s = str(bin(N))[2:]
    last_1 = len(s) - s.index("1")

    s = s[::-1]
    first_1 = s.index("1")

    if last_1 - first_1 == 1:
        print(N, 0)
    else:
        print(pow(2, last_1), last_1 - first_1)
