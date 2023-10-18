L, R = map(int, input().split())

N = R - L + 1
SUM = N * (L + R) // 2

print(SUM % 9)
