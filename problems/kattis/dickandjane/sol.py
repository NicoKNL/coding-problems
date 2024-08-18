from math import ceil, floor

d = 12
while True:
    try:
        s, p, y, j = map(int, input().split())
    except:
        break

    total = d + j

    x = total - s - y
    x /= 3

    print(ceil(x + y), floor(x + s), floor(x))



