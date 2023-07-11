def getNeighbours(r, c, rows, cols):
    neighbours = []

    if r > 0:
        neighbours.append((r - 1, c))

    if c > 0:
        neighbours.append((r, c - 1))

    if c < cols - 1:
        neighbours.append((r, c + 1))

    if r < rows - 1:
        neighbours.append((r + 1, c))

    return neighbours


def buildAdjacency(grid):
    rows = len(grid)
    cols = len(grid[0])

    ADJ = [[[] for _ in range(cols)] for __ in range(rows)]
    for r in range(rows):
        for c in range(cols):
            cur = (r, c)
            height = grid[r][c]
            adj = cur
            for each in getNeighbours(r, c, rows, cols):
                adj_height = grid[each[0]][each[1]]
                if adj_height < height:
                    height = adj_height
                    adj = each

            if adj != cur:
                ADJ[adj[0]][adj[1]].append(cur)
                ADJ[cur[0]][cur[1]].append(adj)

    return ADJ


def flood(adj, grid):
    from string import ascii_lowercase

    rows = len(grid)
    cols = len(grid[0])

    VISITED = [[False for _ in range(cols)] for __ in range(rows)]

    idx = 0

    for r in range(rows):
        for c in range(cols):
            if type(grid[r][c]) == int:
                Q = [(r, c)]
                Qi = 0
                while Qi < len(Q):
                    u, v = Q[Qi]
                    VISITED[u][v] = True
                    grid[u][v] = ascii_lowercase[idx]

                    for each in adj[u][v]:
                        if not VISITED[each[0]][each[1]]:
                            Q.append(each)
                    Qi += 1

                idx += 1


def solveCase():
    rows, cols = map(int, input().split())

    grid = []
    for r in range(rows):
        row = map(int, input().split())
        grid.append(list(row))

    adj = buildAdjacency(grid)

    flood(adj, grid)

    for row in grid:
        print(" ".join(map(str, row)))


if __name__ == "__main__":
    cases = int(input())

    for c in range(1, cases + 1):
        print(f"Case #{c}:")
        solveCase()
