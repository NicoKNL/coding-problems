def findGaps(P, K):
    head = 0
    gaps = []
    tail = 0

    if P[0] > 1:
        head = P[0] - 1

    for i in range(len(P) - 1):
        p_0 = P[i]
        p_1 = P[i + 1]
        
        winning = (p_1 - p_0 - 1)
        
        if winning:
            gaps.append(winning)

    if P[-1] < K:
        tail = K - P[-1]

    return head, gaps, tail


def findBestSingleScore(head, gaps, tail):
    gaps.append(head)
    gaps.append(tail)

    return max(gaps)


def findBestDoubleScore(head, gaps, tail):
    best_two = sorted([head, tail])

    if gaps:
        gaps = sorted([(g + 1) // 2 for g in gaps])
        best_two[0] = max(best_two[0], gaps[-1])

        gaps = gaps[:-1]
        best_two = sorted(best_two)

        if gaps:
            best_two[0] = max(best_two[0], gaps[-1])

    return sum(best_two)


def solve():
    N, K = [int(x) for x in input().split()] 
    P = sorted(list({int(x) for x in input().split()}))

    head, gaps, tail = findGaps(P, K)

    if not head and not gaps and not tail:
        return 0.0

    best_single_score = findBestSingleScore(head, list(gaps), tail) / K
    best_double_score = findBestDoubleScore(head, list(gaps), tail) / K

    return max(best_single_score, best_double_score)


if __name__ == "__main__":
    T = int(input())
    c = 1

    while T:
        print(f"Case #{c}: {solve()}")
        c += 1
        T -= 1

