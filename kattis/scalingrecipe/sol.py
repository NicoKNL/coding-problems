def solve():
    n, x, y = map(int, input().split())

    for _ in range(n):
        actual_portions = int(input())
        print(int(actual_portions * y / x))


if __name__ == "__main__":
    solve()
