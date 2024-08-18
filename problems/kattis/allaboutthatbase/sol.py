from operator import add, sub, mul, truediv, floordiv

OPS = {
    "/": truediv,
    "*": mul,
    "-": sub,
    "+": add,
}

ABC = "0123456789abcdefghijklmnopqrstuvwxyz0"


def convertToDecimal(X, base):
    if base == 1:  # Base 1 is special :O
        if X.count("1") != len(X):
            raise ValueError("Not in base")
        else:
            return len(X)

    value = 0
    for i, c in enumerate(reversed(X)):
        if base <= ABC.index(c):
            raise ValueError("Not in base")
        value += ABC.index(c) * base**i
    return value


def solve():
    X, op, Y, _, Z = input().split()
    bases = []
    for b in range(1, 37):
        try:
            x_ = convertToDecimal(X, b)
            y_ = convertToDecimal(Y, b)
            z_ = convertToDecimal(Z, b)

            if OPS[op](x_, y_) == z_:
                bases.append(ABC[b])

        except:
            pass

    if bases:
        print("".join(bases))
    else:
        print("invalid")


N = int(input())

for _ in range(N):
    solve()
