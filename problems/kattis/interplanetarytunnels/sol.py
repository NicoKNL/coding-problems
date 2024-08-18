from math import ceil

n, m = map(int, input().split())
s, t = map(int, input().split())

adj = [[] for _ in range(n)]
dist = [-1 for _ in range(n)]

for _ in range(m):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

dist[s] = 0
QUEUE = [s]
i = 0

while i < len(QUEUE):
    u = QUEUE[i]
    for v in adj[u]:
        if dist[v] == -1:  # unvisited
            dist[v] = dist[u] + 1
            QUEUE.append(v)

    i += 1

print(ceil(dist[t] / 2))
