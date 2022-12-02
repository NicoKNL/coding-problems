from collections import deque


if __name__ == "__main__":
    N = int(input())
    L = int(input())

    cars = list(map(int, input().split()))
    S = set()

    Q = []
    Qi = 0
    state = (0, 0, 0, 0)
    S.add(state)
    Q.append((state, 0))

    max_i = 0
    while Qi < len(Q):
        prevstate, i = Q[Qi]
        max_i = max(i, max_i)

        for pos in range(4):
            state = list(prevstate)
            if state[pos] == 0:
                if cars[i] <= L:
                    state[pos] = cars[i]
                    state.sort()
                    state = tuple(state)
                    if state not in S:
                        S.add(state)
                        Q.append((state, i + 1))
            else:
                if state[pos] + cars[i] + 1 <= L:
                    state[pos] += cars[i] + 1
                    state.sort()
                    state = tuple(state)
                    if state not in S:
                        S.add(state)
                        Q.append((state, i + 1))

        Qi += 1

    print(max_i)
