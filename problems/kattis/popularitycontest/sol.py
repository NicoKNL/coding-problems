if __name__ == "__main__":
    n, m = map(int, input().split())

    friend_count = [0 for _ in range(n + 1)]

    for _ in range(m):
        a, b = map(int, input().split())
        friend_count[a] += 1
        friend_count[b] += 1

    coeff = friend_count
    for i in range(len(coeff)):
        if i > 0:
            coeff[i] = coeff[i] - i

    print(" ".join(map(str, coeff[1:])))
