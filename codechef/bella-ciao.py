def solve():
    D, d, P, Q = [int(x) for x in str(input()).split(" ")]

    basic_income = D * P

    n_rows = (D - d) // d
    n_cells = int(n_rows * (n_rows + 1) / 2)
    cell_value = d * Q

    remainder = ((D - d) - d * n_rows) * (n_rows + 1) * Q

    sum = basic_income + n_cells * cell_value + remainder

    print(int(sum))


if __name__ == "__main__":
    T = int(input())

    while T:
        solve()
        T -= 1