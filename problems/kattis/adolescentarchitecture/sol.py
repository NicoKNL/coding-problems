from math import sqrt

N = int(input())

stack = []

for _ in range(N):
    t, value = input().split()
    value = int(value)

    if t == "cube":
        r1 = value / 2.0
        r2 = sqrt(2 * r1 * r1)
        stack.append((r1, r2, value))
    else:
        stack.append((value, value, value))

stack.sort()


def isValid(stack):
    for i in range(len(stack) - 1):
        min_r1, max_r1, _ = stack[i]
        min_r2, max_r2, _ = stack[i + 1]

        if min_r2 == max_r2:
            if max_r1 > min_r2:
                return False

    return True


if isValid(stack):
    for radius, edge, original in stack:
        if radius == edge:
            print("cylinder", original)
        else:
            print("cube", original)
else:
    print("impossible")
