import sys

lines = [line.strip() for line in sys.stdin]
GRID = []

for line in lines:
    edges = list(map(int, line.split()))
    GRID.append(edges)

triangles = 0
for col in range(3):
    for row in range(0, len(GRID) - 2, 3):
        edges = [GRID[row][col], GRID[row + 1][col], GRID[row + 2][col]]
        edges.sort()
        if edges[0] + edges[1] > edges[2]:
            triangles += 1

print(triangles)
