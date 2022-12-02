INF = 1e9

if __name__ == "__main__":
    while True:
        n, m, q = map(int, input().split())

        if n == 0 and m == 0 and q == 0:
            break

        dist = [[INF for _ in range(n)] for __ in range(n)]

        for i in range(n):
            dist[i][i] = 0

        for _ in range(m):
            u, v, d = map(int, input().split())
            dist[u][v] = min(dist[u][v], d)

        for k in range(n):
            for i in range(n):
                for j in range(n):
                    if dist[i][k] < INF and dist[k][j] < INF:
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

        for k in range(n):
            for i in range(n):
                for j in range(n):
                    if dist[k][k] < 0 and dist[i][k] != INF and dist[k][j] != INF:
                        dist[i][j] = -INF

        for _ in range(q):
            u, v = map(int, input().split())

            if dist[u][v] == INF:
                print("Impossible")
            elif dist[u][v] == -INF:
                print("-Infinity")
            else:
                print(dist[u][v])
        print()
