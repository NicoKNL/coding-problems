from random import choice
import sys

def solve():
    n = 8

    # outputs = ["10000000", "11000000", "11100000", "11110000", "10101010", "11001100", "11100010"]
    outputs = ["11110000", "10101010", "11001100", "11100010"]
    while n:
        if n > 4:
            print("11111111")
            sys.stdout.flush()
        else:
            print(choice(outputs))
            sys.stdout.flush()
        
        n = int(input())

        if n == -1:
            break



if __name__ == "__main__":
    T = int(input())

    for _ in range(1, T + 1):
        solve()
