def solve():
    n, k = map(int, input().split())

    k = k % pow(2, n)

    if k == pow(2, n) - 1:
        return "ON"

    return "OFF"


if __name__ == "__main__":
    t = int(input())

    for i in range(t):
        print(f"Case #{i + 1}: {solve()}")
