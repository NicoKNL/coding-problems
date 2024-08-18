N, M = map(int, input().split())

NAMES = input().split()
HUNTERS = dict()
for name in NAMES:
    HUNTERS[name] = False

CHEATERS = set()
HUNTERS[NAMES[0]] = True

for _ in range(M):
    u, _, v = input().split()

    if not HUNTERS[u]:
        CHEATERS.add(u)

    HUNTERS[u] = False
    HUNTERS[v] = True

print(len(CHEATERS))
print(" ".join(sorted(CHEATERS)))
