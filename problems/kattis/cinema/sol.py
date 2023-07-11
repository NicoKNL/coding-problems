if __name__ == "__main__":
    seats, _ = map(int, input().split())
    groups = map(int, input().split())

    rejected = 0

    for g in groups:
        if g > seats:
            rejected += 1
        else:
            seats -= g

    print(rejected)
