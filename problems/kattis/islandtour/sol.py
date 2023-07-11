from functools import lru_cache


def printLists():
    global A, B, C
    print(A)
    print(B)
    print(C)


def sortByDuration():
    global A, B, C
    new_order = sorted([(sum(A), A), (sum(B), B), (sum(C), C)], reverse=True)

    A = new_order[0][1]
    B = new_order[1][1]
    C = new_order[2][1]


@lru_cache(None)
def computeIntervals(durations, start):
    intervals = [(-1, -1) for _ in range(N)]
    intervals[start] = (0, durations[start])

    for i in range(1, N):
        cur_i = (start + i) % N
        prev_i = (start + i - 1 + N) % N
        prev_end = intervals[prev_i][1]
        travel_time = distances[prev_i]
        intervals[cur_i] = (
            prev_end + travel_time,
            prev_end + travel_time + durations[cur_i],
        )

    return tuple(intervals)


@lru_cache(None)
def hasOverlap(intervals_1, intervals_2):
    for i in range(N):
        start_1, end_1 = intervals_1[i]
        start_2, end_2 = intervals_2[i]

        if min(end_1, end_2) - max(start_1, start_2) > 0:
            return True

    return False


def simulate2(in1, in2, start_1, start_2):
    intervals_1 = computeIntervals(in1, start_1)
    intervals_2 = computeIntervals(in2, start_2)
    return not hasOverlap(intervals_1, intervals_2)


def simulate3(start_A, start_B, start_C):
    intervals_A = computeIntervals(A, start_A)
    intervals_B = computeIntervals(B, start_B)
    intervals_C = computeIntervals(C, start_C)

    return not (
        hasOverlap(intervals_A, intervals_C) or hasOverlap(intervals_B, intervals_C)
    )


if __name__ == "__main__":
    N = int(input())

    distances = tuple(map(int, input().split()))

    A = tuple(map(int, input().split()))
    B = tuple(map(int, input().split()))
    C = tuple(map(int, input().split()))

    # printLists()
    # sortByDuration()
    # printLists()

    valid_pairs_AB = []

    for start_A in range(N):
        for start_B in range(N):
            if start_A == start_B:
                continue

            no_overlap = simulate2(A, B, start_A, start_B)

            if no_overlap:
                valid_pairs_AB.append((start_A, start_B))

    if not valid_pairs_AB:
        print("impossible")
        exit(0)

    valid_pairs_AC = []

    for start_A in range(N):
        for start_C in range(N):
            if start_A == start_C:
                continue

            no_overlap = simulate2(A, C, start_A, start_C)

            if no_overlap:
                valid_pairs_AC.append((start_A, start_C))

    if not valid_pairs_AC:
        print("impossible")
        exit(0)

    valid_pairs_BC = []

    for start_B in range(N):
        for start_C in range(N):
            if start_B == start_C:
                continue

            no_overlap = simulate2(B, C, start_B, start_C)

            if no_overlap:
                valid_pairs_BC.append((start_B, start_C))

    if not valid_pairs_BC:
        print("impossible")
        exit(0)

    for a1, b1 in valid_pairs_AB:
        for a2, c1 in valid_pairs_AC:
            if a1 != a2:
                continue

            for b2, c2 in valid_pairs_BC:
                if b1 == b2 and c1 == c2:
                    print(a1 + 1, b1 + 1, c1 + 1)
                    exit(0)

    print("impossible")
