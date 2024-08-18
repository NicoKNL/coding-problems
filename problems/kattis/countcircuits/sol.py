from collections import defaultdict

N = int(input())

states = defaultdict(int)
states[(0 + 0j)] = 1  # initialize with 1 for bootstrapping counting

for _ in range(N):
    v = complex(*map(int, input().split()))
    next_states = []
    for u in states.keys():
        count = states[u]

        w = u + v
        next_states.append((w, count))

    for s, count in next_states:
        states[s] += count

print(states[0 + 0j] - 1)  # subtract the bootstrapping 1
