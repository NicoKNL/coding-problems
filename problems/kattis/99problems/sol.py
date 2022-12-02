if __name__ == "__main__":
    n = int(input())
    lo = n
    hi = n

    while lo % 100 != 99 and hi % 100 != 99:
        lo -= 1
        if lo < 0:
            lo = 0
        hi += 1

    if hi % 100 == 99:
        print(hi)
    else:
        print(lo)
