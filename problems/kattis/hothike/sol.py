if __name__ == "__main__":
    n = int(input())

    temps = list(map(int, input().split()))

    best_i = -1
    max_temp = 1e9
    for i in range(n - 2):
        tmp = max(temps[i], temps[i + 2])
        if tmp < max_temp:
            best_i = i + 1
            max_temp = tmp

    print(best_i, max_temp)
