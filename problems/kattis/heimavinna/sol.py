#!/usr/bin/env python3

if __name__ == "__main__":
    problems = input().split(";")
    solve = [0 for i in range(1001)]

    for p in problems:
        if "-" in p:
            r = [int(x) for x in p.split("-")]

            for i in range(r[0], r[1] + 1):
                solve[i] = 1

        else:
            solve[int(p)] = 1

    print(sum(solve))
