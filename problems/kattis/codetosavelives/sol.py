if __name__ == "__main__":
    t = int(input())

    for i in range(t):
        a = int(input().replace(" ", ""))
        b = int(input().replace(" ", ""))

        sum = list(str(a + b))
        print(" ".join(sum))
