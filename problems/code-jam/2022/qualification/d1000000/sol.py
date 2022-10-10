def solve():
    n = int(input())
    dice = sorted(map(int, input().split()))

    result = 1

    for d in dice:
        if d >= result:
            result += 1

    return result - 1


if __name__ == "__main__":
    T = int(input())

    for i in range(1, T + 1):
        print(f"Case #{i}: {solve()}")
