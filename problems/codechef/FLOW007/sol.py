if __name__ == "__main__":
    n = int(input())

    for _ in range(n):
        num = str(input())
        rev = num[::-1].lstrip("0")
        print(rev)
