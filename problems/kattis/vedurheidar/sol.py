wind = int(input())
roads = int(input())

for _ in range(roads):
    road, limit = input().split()
    if int(limit) >= wind:
        print(road + " opin")
    else:
        print(road + " lokud")
