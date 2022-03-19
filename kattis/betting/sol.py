def solve():
    one = float(input())

    one_wins = one / 100.0
    other_wins = (100 - one) / 100.0
    print(f"{1.0 / one_wins:.10f}")
    print(f"{1.0 / other_wins:.10f}")


if __name__ == "__main__":
    solve()
