N, K = map(int, input().split())

found = set()
for _ in range(K):
    obstacle = int(input())
    found.add(obstacle)

for i in range(N):
    if i not in found:
        print(i)

print(f"Mario got {len(found)} of the dangerous obstacles.")
