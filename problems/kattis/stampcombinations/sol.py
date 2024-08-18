_, queries = map(int, input().split())

stamps = list(map(int, input().split()))
prefix = stamps.copy()
suffix = stamps.copy()
for i in range(1, len(stamps)):
    prefix[i] += prefix[i - 1]
    suffix[len(stamps) - i - 1] += suffix[len(stamps) - i]

prefixmap = dict()
for i, v in enumerate(prefix):  # store min index
    if v not in prefixmap:
        prefixmap[v] = i

suffixmap = dict()
for i, v in enumerate(suffix):  # store max index
    suffixmap[v] = i

for _ in range(queries):
    q = int(input())
    if q == 0:
        print("Yes")
        continue

    if q in prefixmap:
        print("Yes")
        continue

    if q in suffixmap:
        print("Yes")
        continue

    searching = True
    for i, v in enumerate(prefix):
        if v > q:
            print("No")
            searching = False
            break

        alt = q - v
        if alt in suffixmap and suffixmap[alt] > i:
            print("Yes")
            searching = False
            break

    if searching:
        print("No")
