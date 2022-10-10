def solve():
    n = int(input())
    grid = []

    for i in range(n):
        row = list(str(input()))
        grid.append(row)

    optimal_cost = 10000000
    cost_tracker = dict()

    # row passes
    for r in range(n):
        cost = 0
        placements = ""
        possible = True
        for c in range(n):
            if grid[r][c] == "X":
                pass
            elif grid[r][c] == ".":
                cost += 1
                placements += f"({r},{c})"
            else:
                possible = False

        if possible and cost <= optimal_cost:
            optimal_cost = cost
            if optimal_cost in cost_tracker:
                cost_tracker[optimal_cost].add(placements)
            else:
                cost_tracker[optimal_cost] = set()
                cost_tracker[optimal_cost].add(placements)

    # col passes
    for c in range(n):
        cost = 0
        placements = ""
        possible = True
        for r in range(n):
            if grid[r][c] == "X":
                pass
            elif grid[r][c] == ".":
                cost += 1
                placements += f"({r},{c})"
            else:
                possible = False

        if possible and cost <= optimal_cost:
            optimal_cost = cost
            if optimal_cost in cost_tracker:
                cost_tracker[optimal_cost].add(placements)
            else:
                cost_tracker[optimal_cost] = set()
                cost_tracker[optimal_cost].add(placements)

    if optimal_cost == 10000000:
        return "Impossible"
    else:
        return f"{optimal_cost} {len(cost_tracker[optimal_cost])}"


if __name__ == "__main__":
    T = int(input())
    c = 1
    while T:
        print(f"Case #{c}: {solve()}")
        T -= 1
        c += 1
