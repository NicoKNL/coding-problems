if __name__ == "__main__":
    m, n = map(int, input().split())

    M = {}

    for _ in range(m):
        word, value = input().split()
        M[word] = int(value)

    value = 0
    while n > 0:
        s = input()
        if s == ".":
            print(value)
            value = 0
            n -= 1
        else:
            s = s.split(" ")
            for w in s:
                if w in M:
                    value += M[w]
