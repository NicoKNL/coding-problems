if __name__ == "__main__":
    days = int(input())

    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = list(map(int, input().split()))

    result = []

    for i in range(days):
        dists = sorted([a[i], b[i], c[i]])
        result.append(dists[1])

    print(" ".join(map(str, result)))
