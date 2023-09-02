import sys
from collections import defaultdict

FLOW = defaultdict(int)
ADJ = defaultdict(list)
VISIT_TIME = defaultdict(int)
MAX_FLOW = 0
MAX_OBSERVED_FLOW_AT_T = defaultdict(int)
NODES = []


def parseInput(lines):
    for line in lines:
        line = line.replace(",", "")
        valve, tunnels = line.split(";")
        valve = valve.split()
        u = valve[1]

        flow = int(valve[-1].split("=")[-1])
        FLOW[u] = flow

        NODES.append(u)

        tunnels = tunnels.split()[4:]
        ADJ[u] = tunnels


def computeFlow():
    global MAX_FLOW

    flow = 0
    for u, t in VISIT_TIME.items():
        if t > 0:
            flow += FLOW[u] * (30 - t)

    MAX_FLOW = max(flow, MAX_FLOW)

    return flow


def done():
    for u, t in VISIT_TIME.items():
        if u == "AA":
            continue

        if t == 0:
            return False
    return True


if __name__ == "__main__":
    lines = [l.strip() for l in sys.stdin]

    parseInput(lines)
    N = len(NODES)
    print(NODES)

    INF = 1e9
    DIST = [[INF for _ in range(N)] for __ in range(N)]

    for i in range(N):
        DIST[i][i] = 0

    for u in ADJ:
        for v in ADJ[u]:
            i = NODES.index(u)
            j = NODES.index(v)
            DIST[i][j] = 1

    for k in range(N):
        for i in range(N):
            for j in range(N):
                DIST[i][j] = min(DIST[i][k] + DIST[k][j], DIST[i][j])

    for row in DIST:
        print(row)

    FLOWNODES = [u for u in range(N) if FLOW[NODES[u]] > 0]
    from itertools import permutations
    from heapq import heappush, heappop

    class Node(object):
        def __init__(self, flow, t, path):
            self.flow = flow
            self.t = t
            self.path = path

        def _heuristic(self):
            return self.flow

        def __lt__(self, other):
            return self._heuristic() < other._heuristic()

    MAX_FLOW = 0
    h = []
    for u in range(N):
        t = DIST[0][u] + 1
        flow = max(0, 30 - t) * FLOW[NODES[u]]
        heappush(h, Node(flow, t, [u]))

    MEMO = defaultdict(int)
    while h:
        print(len(h))
        node = heappop(h)
        flow = node.flow
        t = node.t
        path = node.path
        # print(t, flow, path)
        MAX_FLOW = max(MAX_FLOW, flow)
        if t >= 30:
            continue

        # if t in MEMO and flow < 0.66 * MEMO[t]:
        # continue

        # if flow > MEMO[t]:
        # MEMO[t] = flow

        for u in FLOWNODES:
            if u not in path:
                new_t = DIST[path[-1]][u] + 1
                new_flow = max(0, 30 - (t + new_t)) * FLOW[NODES[u]]
                path.append(u)
                heappush(h, Node(flow + new_flow, t + new_t, path.copy()))
                path = path[:-1]

    print(MAX_FLOW)
