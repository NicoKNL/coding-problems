class Chain:
    def __init__(self, current, parent, value):
        self.current = current
        self.parent = parent
        self.value = value

    def __str__(self):
        return f"{self.current} :: {self.parent} :: {self.value}"


def parseAdjacencyList(n):
    adj = [[] for i in range(n + 1)]

    for i in range(n - 1):
        edge = [int(x) for x in str(input()).split(" ")]
        u = edge[0]
        v = edge[1]
        adj[u].append(v)
        adj[v].append(u)

    return adj


def computeChains(adj, values):
    visited = [False for i in range(len(adj))]
    visited[1] = True

    # leaves
    leaves = []

    for i in range(2, len(adj)):
        if len(adj[i]) == 1:
            leaves.append(i)

    chains = []
    for leaf in leaves:
        visited[leaf] = True
        chains.append(Chain(leaf, -1, values[leaf]))

    done = False
    while not done:
        done = True
        claims = [[] for i in range(len(adj))]

        # Extend chains
        for c in chains:
            while True:
                if c.parent == -1:
                    next_node = adj[c.current][0]
                else:
                    parent_index = adj[c.current].index(c.parent)
                    next_node = adj[c.current][1 - parent_index]

                if len(adj[next_node]) == 2:
                    visited[next_node] = True
                    c.parent = c.current
                    c.current = next_node
                    c.value += values[next_node]
                else:
                    break

        # Put in claims
        for c in chains:
            if c.parent == -1:
                next_node = adj[c.current][0]
            else:
                parent_index = adj[c.current].index(c.parent)
                next_node = adj[c.current][1 - parent_index]

            if not visited[next_node]:
                done = False
                claims[next_node].append(c)

        if not done:
            # Resolve claims
            for i, claim_list in enumerate(claims):
                if i == 0:
                    continue

                if claim_list:
                    best_chain = Chain(-1, -1, -1)

                    for chain in claim_list:
                        if chain.value > best_chain.value:
                            best_chain = chain

                    visited[i] = True
                    best_chain.parent = best_chain.current
                    best_chain.current = i
                    best_chain.value += values[i]

    return chains


def solve():
    n = int(input())

    values = [int(x) for x in str(input()).split(" ")]
    values.insert(0, 0)  # make 1 based
    adj = parseAdjacencyList(n)
    chains = computeChains(adj, values)

    chains.sort(key=lambda x: x.value, reverse=True)
    result = values[1]

    if len(chains) >= 1:
        result += chains[0].value

    if len(chains) >= 2:
        for c in chains[1:]:
            if c.current in adj[1]:
                result += c.value
                break

    return result


if __name__ == "__main__":
    T = int(input())
    c = 1
    while T:
        print(f"Case #{c}: {solve()}")
        T -= 1
        c += 1
