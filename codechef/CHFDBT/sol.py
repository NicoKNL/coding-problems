from math import ceil

if __name__ == "__main__":
    T = int(input())

    for _ in range(T):
        N = int(input())
        print(ceil(N / 2))
