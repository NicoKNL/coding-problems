if __name__ == "__main__":
    while True:
        given, actual, lo, hi = map(int, input().split())

        target = int(given * 1000 / 75)

        # print(given, actual, lo, hi)
        print("-" * 80)
        print(
            given,
            f"-{target}-",
            actual,
            abs(given - actual),
            given / actual,
            f"..{abs(actual - target)}..",
        )
