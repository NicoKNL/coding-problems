if __name__ == "__main__":
    TARGET = 34000000
    presents = [0 for _ in range(1000000)]

    i = 1
    while i < len(presents):
        print(i)
        v = i
        while v < len(presents):
            presents[v] += i * 10
            v += i
        i += 1

    for i, count in enumerate(presents):
        if count >= TARGET:
            print(i)
            break
