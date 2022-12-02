if __name__ == "__main__":
    n = int(input())

    M = []
    for _ in range(n):
        M.append(list(map(int, input().split())))

    arr = []

    for i in range(n):
        num = 0
        for j in range(n):
            if i == j:
                continue

            num |= M[i][j]

        arr.append(num)

    print(" ".join(map(str, arr)))
