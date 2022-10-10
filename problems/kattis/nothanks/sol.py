if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split()))
    arr.sort()

    smallest = [arr[0]]
    for i in range(len(arr) - 1):
        if arr[i + 1] - arr[i] != 1:
            smallest.append(arr[i + 1])

    print(sum(smallest))
