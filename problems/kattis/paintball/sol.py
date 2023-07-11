from collections import defaultdict


class Graph:
    def __init__(self, vertices):
        self.V = vertices  # No. of vertices
        self.graph = defaultdict(list)  # default dictionary to store graph
        self.Time = 0
        self.bridges = []

    def addEdge(self, u, v):
        self.graph[u].append(v)
        self.graph[v].append(u)

    """A recursive function that finds and prints bridges
    using DFS traversal
    u --> The vertex to be visited next
    visited[] --> keeps track of visited vertices
    disc[] --> Stores discovery times of visited vertices
    parent[] --> Stores parent vertices in DFS tree"""

    def bridgeUtil(self, u, visited, parent, low, disc):
        # Mark the current node as visited and print it
        visited[u] = True

        # Initialize discovery time and low value
        disc[u] = self.Time
        low[u] = self.Time
        self.Time += 1

        # Recur for all the vertices adjacent to this vertex
        for v in self.graph[u]:
            # If v is not visited yet, then make it a child of u
            # in DFS tree and recur for it
            if visited[v] == False:
                parent[v] = u
                self.bridgeUtil(v, visited, parent, low, disc)

                # Check if the subtree rooted with v has a connection to
                # one of the ancestors of u
                low[u] = min(low[u], low[v])

                """ If the lowest vertex reachable from subtree
                under v is below u in DFS tree, then u-v is
                a bridge"""
                if low[v] > disc[u]:
                    self.bridges.append((u, v))

            elif v != parent[u]:  # Update low value of u for parent function calls.
                low[u] = min(low[u], disc[v])

    # DFS based function to find all bridges. It uses recursive
    # function bridgeUtil()
    def bridge(self):
        # Mark all the vertices as not visited and Initialize parent and visited,
        # and ap(articulation point) arrays
        visited = [False] * (self.V)
        disc = [float("Inf")] * (self.V)
        low = [float("Inf")] * (self.V)
        parent = [-1] * (self.V)

        # Call the recursive helper function to find bridges
        # in DFS tree rooted with vertex 'i'
        for i in range(self.V):
            if visited[i] == False:
                self.bridgeUtil(i, visited, parent, low, disc)

    def removeBridges(self):
        for u, v in self.bridges:
            self.graph[u].remove(v)
            self.graph[v].remove(u)

    def isTriviallyPossible(self):
        for u, adj_u in self.graph.items():
            if len(adj_u) != 1:
                return False

        return True

    def isPossible(self):
        for u, adj_u in self.graph.items():
            if len(adj_u) == 0:
                return False
        return True

    def traverse(self):
        visited = [False] * self.V
        assign = [-1] * self.V

        for u in range(self.V):
            if visited[u]:
                continue
            visited[u] = True

            Q = [u]
            Qi = 0
            while Qi < len(Q):
                s = Q[Qi]

                for t in self.graph[s]:
                    if not visited[t]:
                        visited[t] = True
                        Q.append(t)
                        assign[s] = t
                        break

                Qi += 1

            assign[s] = u

        for v in assign:
            print(v + 1)


if __name__ == "__main__":
    N, M = map(int, input().split())

    graph = Graph(N)

    for _ in range(M):
        u, v = map(int, input().split())
        graph.addEdge(u - 1, v - 1)

    if graph.isTriviallyPossible():
        graph.traverse()
        exit(0)

    graph.bridge()
    graph.removeBridges()
    if not graph.isPossible():
        print("Impossible")
    else:
        graph.traverse()
