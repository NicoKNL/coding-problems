from math import ceil


def solve():
    xa, xb, XA, XB = [int(x) for x in str(input()).split(" ")]
    print((ceil(XA / xa)) + int(ceil(XB / xb)))


if __name__ == "__main__":
    T = int(input())

    while T:
        solve()
        T -= 1