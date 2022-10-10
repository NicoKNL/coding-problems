def solve():
    s = input().lower()
    count = [s.count(c) for c in "aeiou"]
    print(sum(count))


if __name__ == "__main__":
    solve()
