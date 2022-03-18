def solve():
    solves = sorted([int(s.replace(".", "")) * 10 for s in input().split()])
    target = int(input().replace(".", "")) * 10

    worst_to_come = solves[1:]
    best_to_come = solves[:3]
    best_and_worst_done = solves[1:3]
    best = solves[0]
    worst = solves[-1]

    if sum(worst_to_come) // 3 <= target:
        print("infinite")
        return

    if sum(best_to_come) // 3 > target:
        print("impossible")
        return

    current = worst
    while current >= best:
        current_result = (sum(best_and_worst_done) + current) // 3
        if current_result <= target:
            print(f"{(current - 2)/1000.0:.2f}")
            return
        current -= 1

    print("impossible")


if __name__ == "__main__":
    solve()
