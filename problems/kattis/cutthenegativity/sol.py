if __name__ == "__main__":
    n = int(input())

    adjmat = []
    total = 0

    for _ in range(n):
        adjmat.append(list(map(int, input().split())))
        total += sum([1 if x > 0 else 0 for x in adjmat[-1]])

    print(total)
    for u in range(n):
        for v in range(n):
            if u != v and adjmat[u][v] != -1:
                print(u + 1, v + 1, adjmat[u][v])
