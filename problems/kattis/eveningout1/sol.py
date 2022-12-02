if __name__ == "__main__":
    A, B = map(int, input().split())

    if A <= B:
        print(min(A, B - A))
    else:
        m = A % B
        print(min(B - m, m))
