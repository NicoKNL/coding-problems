classrooms, bottles = map(int, input().split())

total = 0
for _ in range(classrooms):
    total += int(input())

if total <= bottles:
    print("Jebb")
else:
    print("Neibb")
