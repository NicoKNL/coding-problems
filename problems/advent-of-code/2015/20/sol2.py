if __name__ == "__main__":
    TARGET = 34000000
    presents = [0 for _ in range(1000000)]

    i = 1
    count = 0
    while i < len(presents):
        print(i)
        v = i
        while v < len(presents) and count < 50:
            presents[v] += i * 11
            v += i
            count += 1
        i += 1
        count = 0

    for i, count in enumerate(presents):
        if count >= TARGET:
            print(i)
            break
