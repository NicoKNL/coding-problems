if __name__ == "__main__":
    n, d = map(int, input().split())
    days = list(map(int, input().split()))

    days_this_year = d
    year_count = -1
    for i, year in enumerate(days):
        if year <= days_this_year:
            year_count = i
            break

    if year_count == -1:
        print("It had never snowed this early!")
    else:
        print(f"It hadn't snowed this early in {year_count} years!")
