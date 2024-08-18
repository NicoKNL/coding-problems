import sys
import networkx as nx
import matplotlib.pyplot as plt

lines = [line.strip() for line in sys.stdin]
G = nx.Graph()
forbidden = [
    ("zjm", "zcp"),
    ("jks", "rfg"),
    ("nsk", "rsg"),
]

for line in lines:
    print(line)
    u, line = line.split(":")
    for v in line.strip().split():
        print(u, v)
        if (u, v) in forbidden or (v, u) in forbidden:
            continue
        G.add_edge(u, v)

print(list(len(x) for x in list(nx.connected_components(G))))
# pos = nx.spring_layout(G, seed=42)
# nx.draw(G, pos, with_labels=True)
# plt.show()
