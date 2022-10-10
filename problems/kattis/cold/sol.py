#!/usr/bin/env python3

if __name__ == "__main__":
    N = int(input())
    V = map(int, input().split())
    total = 0

    for temp in V:
        if temp < 0:
            total += 1

    print(total)
