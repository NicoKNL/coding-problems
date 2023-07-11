SOLUTIONS = []


def addSolution(tracker, names):
    global solutions

    sol = []
    for i in tracker:
        sol.append(names[i])

    SOLUTIONS.append(" ".join(sol))


def dfs(tracker, visited, depth, target, adj, names):
    if depth == target:
        return addSolution(tracker, names)

    u = tracker[depth]
    for v in range(len(visited)):
        if not visited[v]:
            if v in adj[u]:
                visited[v] = True
                tracker[depth + 1] = v
                dfs(
                    tracker,
                    visited,
                    depth + 1,
                    target,
                    adj,
                    names,
                )
                visited[v] = False
                tracker[depth + 1] = -1


def solve():
    global SOLUTIONS
    SOLUTIONS = []

    n = int(input())

    adj = [set(list(range(n))) for _ in range(n)]
    for i, student in enumerate(adj):
        student.remove(i)

    names = []
    for _ in range(n):
        names.append(input())

    m = int(input())

    for _ in range(m):
        person_a, person_b = input().split()

        u = names.index(person_a)
        v = names.index(person_b)

        adj[u].remove(v)
        adj[v].remove(u)

    for u in range(n):
        tracker = [-1 for _ in range(n)]
        visited = [False for _ in range(n)]
        tracker[0] = u
        visited[u] = True

        dfs(
            tracker,
            visited,
            0,
            n - 1,
            adj,
            names,
        )

    if not SOLUTIONS:
        print("You all need therapy.")
    else:
        SOLUTIONS.sort()
        print(SOLUTIONS[0])


if __name__ == "__main__":
    while True:
        try:
            solve()
        except EOFError:
            break
