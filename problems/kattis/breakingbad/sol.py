from collections import defaultdict

N = int(input())

COLORING = dict()
for _ in range(N):
    COLORING[input()] = 0

GRAPH = defaultdict(list)
M = int(input())
for _ in range(M):
    a, b = input().split()
    GRAPH[a].append(b)
    GRAPH[b].append(a)

for item, color in COLORING.items():
    if color:
        continue

    COLORING[item] = 1
    Q = [item]
    while Q:
        u = Q.pop()
        next_color = 3 - COLORING[u]  # 3 - 2 => 1, 3 - 1 => 2
        for v in GRAPH[u]:
            if COLORING[v] == next_color:
                continue
            if COLORING[v] != 0:
                print("impossible")
                exit(0)
            COLORING[v] = next_color
            Q.append(v)

one = [k for k, v in COLORING.items() if v == 1]
two = [k for k, v in COLORING.items() if v == 2]
print(" ".join(one))
print(" ".join(two))
