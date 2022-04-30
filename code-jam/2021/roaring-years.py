def isRoaringBasedOnStartWidth(y, prev, start, width):
    if start >= len(y):
        return True

    if start + width > len(y):
        return False

    if y[start] == "0":
        return False

    current = int(y[start:start + width])

    if prev + 1 == current:
        return isRoaringBasedOnStartWidth(y, current, start + width, width)
    elif prev + 1 > current:
        return isRoaringBasedOnStartWidth(y, prev, start, width + 1)
    else:
        return False


def isRoaringWithoutLength(y):
    width = 1

    while width <= len(y) // 2:
        if isRoaringBasedOnStartWidth(y, int(y[:width]), width, width):
            return True
        
        width += 1

    return False


def isRoaringWithLength(y, n):
    if len(y) % n > 0: 
        return False

    start = 0
    end   = len(y)
    step  = n

    chunks = []
    for i in range(start, end, step):
        chunks.append(int(y[i:i + step]))

    print(chunks)
    if len(chunks) == 1:
        return False

    for i in range(len(chunks) - 1):
        if chunks[i] + 1 != chunks[i + 1]:
            return False

    return True 


def isRoaring(y):
    if isRoaringWithoutLength(y):
        return True

    # for i in range(1, 9):
        # if isRoaringWithLength(y, i):
        #     return True

    return False


def bruteForce():
    Y = str(input())

    Y = str(int(Y) + 1)

    while not isRoaring(Y):
        Y = str(int(Y) + 1)

    return Y

if __name__ == "__main__":
    T = int(input())
    c = 1

    while T:
        print(f"Case #{c}: {bruteForce()}")
        c += 1
        T -= 1

