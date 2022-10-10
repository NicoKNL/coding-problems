if __name__ == "__main__":
    n = int(input())

    for _ in range(n):
        num = str(input())
        answer = sum([int(x) for x in num])
        print(answer)
