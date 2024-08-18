friends, days, today = map(int, input().split())

count = 0
for _ in range(friends):
    day = int(input())
    if day + 14 <= today + days:
        count += 1
print(count)
