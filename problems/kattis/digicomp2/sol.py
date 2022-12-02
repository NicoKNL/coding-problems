def flip(state):
    if state == "R":
        return "L"
    else:
        return "R"


if __name__ == "__main__":
    n, states = map(int, input().split())

    switches = ["L" for _ in range(states + 1)]
    parents = [0 for _ in range(states + 1)]
    adj = [[] for _ in range(states + 1)]

    for s in range(1, states + 1):
        direction, left_child, right_child = input().split()
        left_child = int(left_child)
        right_child = int(right_child)

        switches[s] = direction
        adj[s] = [left_child, right_child]
        parents[left_child] += 1
        parents[right_child] += 1

    BALLS = [0 for _ in range(states + 1)]
    BALLS[1] = n

    queue = []
    qi = 0

    for i, count in enumerate(parents):
        if count == 0:
            queue.append(i)

    while qi < len(queue):
        u = queue[qi]
        balls = BALLS[u]

        if adj[u]:
            left, right = adj[u]

        if balls % 2 == 1:
            if adj[u]:
                if switches[u] == "L":
                    BALLS[left] += 1
                else:
                    BALLS[right] += 1

            switches[u] = flip(switches[u])

        if adj[u]:
            BALLS[left] += balls // 2
            parents[left] -= 1
            if parents[left] == 0:
                queue.append(left)

            BALLS[right] += balls // 2
            parents[right] -= 1
            if parents[right] == 0:
                queue.append(right)

        qi += 1

    print("".join(switches[1:]))
