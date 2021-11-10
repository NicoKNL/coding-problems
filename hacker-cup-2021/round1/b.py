def solve_small_case(n, m, a, b):
    min_overlap = min(n, m) * 1000 # = 2000
    max_overlap = max(n, m) * 1000

    if a < min_overlap or b < min_overlap:
        return "Impossible"

    if a > max_overlap or b > max_overlap:
        return "Impossible"

    if 
    grid = [[0] * m for _ in range(n)]
    

def solve():
    n, m, a, b = [int(x) for x in input().split(" ")]

    if a < n * m or b < n * m:
        return "Impossible"

    if a > (n * m) * 1000 or b > (n * m) * 1000:
        return "Impossible"

    if n == 2 or m == 2:
        return solve_small_case(n, m, a, b)

    return solve_general_case(n, m, a, b)


if __name__ == "__main__":
    T = int(input())
    c = 1
    while T:
        print(f"Case #{c}: {solve()}")
        T -= 1
        c += 1
