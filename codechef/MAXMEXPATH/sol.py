def solve():
    n = int(input())
    val = list(map(int, input().split()))

    adj = [[] for _ in range(n)]

    for _ in range(n):
        u, v = map(int, input().split())
        adj[u].append(v)
        adj[v].append(u)

    # bfs_mex(n, adj, val) ...


if __name__ == "__main__":
    T = int(input())

    for _ in range(T):
        solve()
