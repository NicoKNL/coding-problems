import sys

lines = [line.strip() for line in sys.stdin]

triangles = 0
for line in lines:
    edges = list(map(int, line.split()))
    edges.sort()
    if edges[0] + edges[1] > edges[2]:
        triangles += 1

print(triangles)
