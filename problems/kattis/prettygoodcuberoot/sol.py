import sys


def get_lower_and_upper_bound(n):
    i = 1
    while pow(i, 3) < n:
        i *= 2

    if pow(i, 3) == n:
        return (i, i)

    lower = i // 2
    upper = i

    return (lower, upper)


def closest_to_n(n, lower, upper):
    diff_below = n - pow(lower, 3)
    diff_above = pow(upper, 3) - n

    if diff_below < diff_above:
        return lower
    else:
        return upper


def search_approximate_cube_root(n, lower, upper):
    if upper - lower == 1:
        return closest_to_n(n, lower, upper)

    center = (lower + upper) // 2

    if pow(center, 3) < n:
        return search_approximate_cube_root(n, center, upper)
    elif pow(center, 3) > n:
        return search_approximate_cube_root(n, lower, center)
    else:  # center == cube_root_of n
        return center


def solve(n):
    n = int(n)
    if n == 0:
        print(0)
        return

    lower, upper = get_lower_and_upper_bound(n)

    approx_cube_root = search_approximate_cube_root(n, lower, upper)
    print(approx_cube_root)


if __name__ == "__main__":
    for line in sys.stdin:
        solve(line.strip())
