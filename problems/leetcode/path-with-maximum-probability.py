class Node:
    def __init__(self):
        self.dist = 0
        self.visited = False
        self.neighbors = []
    
    def addNeighbor(self, neighbor, dist):
        self.neighbors.append((neighbor, dist))


class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start_node: int, end_node: int) -> float:
        # heapqueue dijkstra
        nodes = dict()

        for node in range(n):
            nodes[node] = Node()

        for dist, (u, v) in zip(succProb, edges):
            nodes[u].addNeighbor(v, dist)
            nodes[v].addNeighbor(u, dist)

        nodes[start_node].dist = 1
        Q=[(1 - nodes[start_node].dist, start_node)] # priority queue

        while Q:
            _, node = heapq.heappop(Q)
            dist = nodes[node].dist

            if nodes[node].visited:
                continue
        
            nodes[node].visited = True
            for neighbor, dist_to_neighbor in nodes[node].neighbors:
                if nodes[neighbor].visited:
                    continue

                next_dist = dist * dist_to_neighbor

                if next_dist > nodes[neighbor].dist:
                    nodes[neighbor].dist = next_dist
                    heapq.heappush(Q, (1 - next_dist, neighbor))

        return nodes[end_node].dist
