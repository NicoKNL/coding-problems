from math import sqrt

if __name__ == "__main__":
    L, R = map(int, input().split())

    diagonal = sqrt(L * L + L * L)

    if diagonal <= 2 * R:
        print("fits")
    else:
        print("nope")
