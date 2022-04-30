from collections import deque

def solve():
    n = input()
    D = deque(map(int, input().split()))

    total = 0
    highest = -1
    while len(D):
        first = D[0]
        last = D[-1]

        if first < last:
            pick = D.popleft()
        else:
            pick = D.pop()

        if pick >= highest:
            highest = pick
            total += 1
    
    return total


if __name__ == "__main__":
    T = int(input())

    for i in range(1, T + 1):
        print(f"Case #{i}: {solve()}")
