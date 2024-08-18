from typing import List, Tuple

class Color:

    index: int
    n_nodes: int

    def __init__(self, index) -> None:
        self.index = index
        self.n_nodes = 0

    def __repr__(self):
        return f"C{self.index}"

    def add_node(self):
        self.n_nodes = self.n_nodes + 1

class Node:

    neighbors: List['Node']
    index: int
    color: Color

    def __init__(self, index):
        self.index = index
        self.neighbors = []
        self.color = None

    def __repr__(self) -> str:
        return f"N{self.index}|{self.color}"

    def add_neighbor(self, node: 'Node'):
        if node not in self.neighbors:
            self.neighbors.append(node)

    def set_color(self, color: Color):
        self.color = color
        color.add_node()

    @property
    def neighbor_colors(self):
        return [n.color for n in self.neighbors if n.color is not None]

    @property
    def saturation(self):
        return len(set((n.color for n in self.neighbors if n.color is not None)))

    @property
    def degree(self):
        return len(self.neighbors)



class DSatur:

    N: List[Node]
    C: List[Color]
    history: List[Node]

    def __init__(self, nodes: List[int], edges: List[Tuple[int, int]]):
        N = [Node(i) for i in nodes]
        for e in edges:
            i, j = e
            N[i].add_neighbor(N[j])
            N[j].add_neighbor(N[i])
        self.N = N
        self.C = []
        self.history = []

    def find_next_color(self, node: Node) -> Color:
        next_color = None
        for c in self.C:
            if c not in node.neighbor_colors:
                next_color = c
                break
        if next_color is None:
            next_color = Color(len(self.C) + 1)
            self.C.append(next_color)
        return next_color

    def solve(self, save_history=False):
        Q = [n for n in self.N]  # Pool of uncolored nodes
        while len(Q) > 0:
            Q.sort(key=lambda x: (x.saturation, x.degree), reverse=True)
            n: Node = Q.pop(0)
            next_color = self.find_next_color(n)
            n.set_color(next_color)
            if save_history:
                self.history.append(n)
        self.C.sort(key=lambda x: x.n_nodes, reverse=True)

    @property
    def cost(self):
        return len(self.C) 
 
# Driver Code
if __name__ == '__main__':
    n, k = map(int, input().split())
    nodes = set(range(n))
    edges = []
    for _ in range(n - 1):
        u, v = map(int, input().split())
        edges.append((u - 1, v - 1))
    
    dsatur = DSatur(nodes, edges)
    dsatur.solve()
    print(dsatur.C)
 
 
