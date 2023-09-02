import re
from itertools import combinations
from multiprocessing import Pool, cpu_count
from typing import Dict, List


def dijkstra(graph: Dict[str, List[str]], source: str) -> Dict[str, int]:
    Q = list(graph.keys())
    dist = {v: 99 for v in graph}
    dist[source] = 0

    while Q:
        u = min(Q, key=dist.get)
        Q.remove(u)

        for v in graph[u]:
            alt = dist[u] + 1
            if alt < dist[v]:
                dist[v] = alt

    return dist


def dfs(
    valve: str,
    t: int,
) -> int:
    paths = []

    def _dfs(valve: str, t: int, visited: List[str]):
        if t <= 0:
            return

        for next_valve, d in distances[valve].items():
            if not rates[next_valve]:
                continue

            if next_valve in visited:
                continue

            if t - d - 1 <= 0:
                continue

            _dfs(next_valve, t - d - 1, [*visited, next_valve])

        paths.append(visited)

    _dfs(valve, t, [])

    return paths


def path_score(path: List[str], t: int) -> int:
    score = 0
    for valve, next_valve in zip(["AA", *path], path):
        t -= distances[valve][next_valve] + 1
        score += t * rates[next_valve]

    return score


def pair_path_score(pair):
    a, b = pair
    if set(a).isdisjoint(set(b)):
        return path_score(a, 26) + path_score(b, 26)
    else:
        return 0


inputs = [
    re.search(
        r"Valve (\w+) has flow rate=(\d+); tunnels? leads? to valves?" r" (.*)",
        x,
    ).groups()
    for x in open("2.in").readlines()
]

graph = {valve: tunnels.split(", ") for valve, _, tunnels in inputs}
rates = {valve: int(rate) for valve, rate, _ in inputs}
distances = {valve: dijkstra(graph, valve) for valve in graph}

if __name__ == "__main__":
    paths = dfs("AA", 30)
    print(max(path_score(p, 30) for p in paths))

    paths = dfs("AA", 26)
    with Pool(cpu_count()) as p:
        print(max(p.imap_unordered(pair_path_score, combinations(paths, 2), 1_000)))
