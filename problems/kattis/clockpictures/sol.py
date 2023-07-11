from collections import defaultdict


def computeDeltas(L):
    L.sort()
    L.append(L[0])
    return [((t2 - t1) + 360000) % 360000 for t1, t2 in zip(L, L[1:])]


def getNumberCounts(L):
    d = defaultdict(int)
    for num in L:
        d[num] += 1
    return d


if __name__ == "__main__":
    n = int(input())
    clock1 = list(map(int, input().split()))
    clock2 = list(map(int, input().split()))

    deltas1 = computeDeltas(clock1)
    deltas2 = computeDeltas(clock2)

    if getNumberCounts(deltas1) != getNumberCounts(deltas1):
        print("impossible")
        exit()

    counts = getNumberCounts(deltas1)
    needle = min(counts, key=counts.get)

    starts = [i for i in range(len(deltas2)) if deltas2[i] == needle]

    for start in starts:
        head = deltas2[0:start]
        tail = deltas2[start:]
        tail.extend(head)

        if tail == deltas1:
            print("possible")
            exit()

    print("impossible")
