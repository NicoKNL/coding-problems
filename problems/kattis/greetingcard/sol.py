from math import sqrt

n = int(input())

positions = set()

for _ in range(n):
    x, y = map(int, input().split())
    positions.add((x, y))

count = 0
pairs = set()
for x, y in positions:
    for xo, yo in [
        (0, 2018),
        (2018, 0),
        (1118, 1680),
        (1680, 1118),
    ]:
        if (x + xo, y + yo) in positions:
            pairs.add(((x, y), (x + xo, y + yo)))
        if (x - xo, y - yo) in positions:
            pairs.add(((x, y), (x - xo, y - yo)))
        if (x + xo, y - yo) in positions:
            pairs.add(((x, y), (x + xo, y - yo)))
        if (x - xo, y + yo) in positions:
            pairs.add(((x, y), (x - xo, y + yo)))

print(len(pairs) // 2)
