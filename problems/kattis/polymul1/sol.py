if __name__ == "__main__":
    T = int(input())

    for _ in range(T):
        __ = input()
        poly_a = list(map(int, input().split()))

        __ = input()
        poly_b = list(map(int, input().split()))

        mult = [0 for ___ in range(len(poly_a) + len(poly_b) - 1)]

        for i, a in enumerate(poly_a):
            for ii, b in enumerate(poly_b):
                mult[i + ii] += a * b
        print(len(mult) - 1)
        print(" ".join(map(str, mult)))
