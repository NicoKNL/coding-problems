def find_all_segment_start_and_ends(beads, target):
    n = len(beads)

    segments = [-1 for _ in range(len(beads))]
    beads.extend(beads)

    start = 0
    end = 0
    running_sum = beads[start]

    while start < len(beads) - 1 and end < len(beads) - 1:
        if running_sum == target:
            if segments[start % n] == (end % n):
                break
            else:
                segments[start % n] = end % n
            running_sum -= beads[start]
            start += 1
            end += 1
            running_sum += beads[end]

        elif running_sum < target:
            end += 1
            running_sum += beads[end]

        else:  # running_sum > target
            running_sum -= beads[start]
            start += 1

    return segments


def solve():
    k, n = map(int, input().split())

    beads = list(map(int, input().split()))
    SUM = sum(beads)
    TARGET = SUM // k

    # Early outs
    if k <= 1:
        print("YES")
        return

    if n == 0:
        print("YES")
        return

    if SUM % k != 0:
        print("NO")
        return

    if SUM == 0:
        print("YES")
        return

    for b in beads:
        if b > TARGET:
            print("NO")
            return

    # Track start and end points of all segments
    segments = find_all_segment_start_and_ends(beads, TARGET)

    # Step throug all possible start segments and see if this
    # leads to finding k adjacent segments
    for start, end in enumerate(segments):
        count = 0
        while end != -1:
            start = (end + 1) % n
            end = segments[start]
            count += 1

            if count == k:
                print("YES")
                return

    print("NO")


if __name__ == "__main__":
    solve()
