if __name__ == "__main__":
    n = int(input())

    arr = []
    for _ in range(n):
        arr.append(int(input()))

    inversions = 0

    prev = arr[0]
    for cur in arr[1:]:
        if cur < prev:
            inversions += 1
        prev = cur

    print(inversions + 1)
