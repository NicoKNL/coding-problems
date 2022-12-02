from math import ceil

ADJ = None
GROUPID = None
GROUPS = None
VISITED = None
HEIGHT = None
OPT_TREE_HEIGHTS = None


def flood(u, gid):
    GROUPS[gid] = [u]
    queue = [u]
    qi = 0
    VISITED[u] = True
    GROUPID[u] = gid

    while qi < len(queue):
        u = queue[qi]
        for v in ADJ[u]:
            if not VISITED[v]:
                VISITED[v] = True
                GROUPID[v] = gid
                queue.append(v)
                GROUPS[gid].append(v)
        qi += 1


def get_opt_height(gid):
    nodes = GROUPS[gid]
    leaves = [u for u in nodes if len(ADJ[u]) <= 1]

    queue = leaves
    qi = 0

    max_height = -1

    while qi < len(queue):
        u = queue[qi]

        max_height = max(max_height, HEIGHT[u])

        for v in ADJ[u]:
            VISIT_COUNT[v] += 1
            if VISIT_COUNT[v] == len(ADJ[v]) - 1:
                heights = [HEIGHT[w] + 1 for w in ADJ[v]]
                HEIGHT[v] = max(heights)
                queue.append(v)

        qi += 1

    return max_height


def get_opt_internal_dist(gid, max_height):
    nodes = [u for u in GROUPS[gid] if HEIGHT[u] == max_height and len(ADJ[u]) >= 1]
    max_two_height = 0
    for u in nodes:
        adj_heights = [HEIGHT[v] + 1 for v in ADJ[u]]
        adj_heights.sort(reverse=True)
        max_two_height = max(max_two_height, sum(adj_heights[:2]))

    return max_two_height


if __name__ == "__main__":
    computers, cables = map(int, input().split())

    ADJ = [[] for _ in range(computers)]

    for _ in range(cables):
        u, v = map(int, input().split())
        ADJ[u].append(v)
        ADJ[v].append(u)

    gid = 0
    GROUPID = [-1 for _ in range(computers)]
    GROUPS = dict()
    VISITED = [False for _ in range(computers)]

    for u in range(computers):
        if GROUPID[u] == -1:
            flood(u, gid)
            gid += 1

    HEIGHT = [0 for _ in range(computers)]
    VISIT_COUNT = [0 for _ in range(computers)]
    OPT_TREE_HEIGHTS = [0 for _ in range(gid)]
    OPT_INTERNAL_DIST = [0 for _ in range(gid)]

    for i in range(gid):
        OPT_TREE_HEIGHTS[i] = get_opt_height(i)
        OPT_INTERNAL_DIST[i] = get_opt_internal_dist(i, OPT_TREE_HEIGHTS[i])

    OPT_TREE_HEIGHTS.sort(reverse=True)
    OPT_INTERNAL_DIST.sort(reverse=True)

    options = []
    if gid >= 1:
        options.append(OPT_INTERNAL_DIST[0])
    if gid >= 2:
        h1, h2 = OPT_INTERNAL_DIST[:2]
        h1 = ceil(h1 / 2)
        h2 = ceil(h2 / 2)
        options.append(h1 + h2 + 1)
    if gid >= 3:
        h1, h2, h3 = OPT_INTERNAL_DIST[:3]
        h1 = ceil(h1 / 2)
        h2 = ceil(h2 / 2)
        h3 = ceil(h3 / 2)
        options.append(h2 + h3 + 2)

    print(max(options))
