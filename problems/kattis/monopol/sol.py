N = int(input())
hotels = list(map(int, input().split()))

hit = 0
miss = 0

for i in range(1, 7):
    for ii in range(1, 7):
        if i + ii in hotels:
            hit += 1
        else:
            miss += 1

print(hit / (hit + miss))
