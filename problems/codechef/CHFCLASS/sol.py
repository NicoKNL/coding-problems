if __name__ == "__main__":
    T = int(input())

    for _ in range(T):
        N = int(input())

        if N >= 6:
            result = 1
            N -= 6
            result += N // 7
            print(result)
        else:
            print(0)
