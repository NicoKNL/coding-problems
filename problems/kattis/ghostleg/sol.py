n, m = map(int, input().split())

rungs = [int(input()) for _ in range(m)]
order = [-1 for _ in range(n)]
for i in range(1, n + 1):
    pos = i
    for rung in rungs:
        if rung == pos:
            pos += 1
        elif rung == pos - 1:
            pos -= 1
    order[pos - 1] = i

for each in order:
    print(each)
