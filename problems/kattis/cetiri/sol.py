if __name__ == "__main__":
    arr = list(map(int, input().split()))
    arr.sort()

    if abs(arr[1] - arr[0]) == abs(arr[2] - arr[1]):
        print(arr[-1] + arr[1] - arr[0])
    else:
        diff1 = abs(arr[1] - arr[0])
        diff2 = abs(arr[2] - arr[1])

        if diff1 > diff2:
            print(arr[0] + diff2)
        else:
            print(arr[1] + diff1)
