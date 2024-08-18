from functools import lru_cache

N, M = map(int, input().split())

parents = dict()

main = input()

for _ in range(N):
    child, p1, p2 = input().split()
    parents[child] = (p1, p2)


@lru_cache(maxsize=None)
def getPurity(name):
    if name == main:
        return 1.0

    if name not in parents:
        return 0.0

    p1, p2 = parents[name]
    return (getPurity(p1) + getPurity(p2)) / 2.0


claims = []
for _ in range(M):
    name = input()
    claims.append((getPurity(name), name))

claims.sort(reverse=True)
print(claims[0][1])
