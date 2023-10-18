N = int(input())

A = 0
B = 0
C = 0

for _ in range(N):
    a, b, c = input().split()
    if a == "J":
        A += 1
    if b == "J":
        B += 1
    if c == "J":
        C += 1

print(min(A, B, C))
