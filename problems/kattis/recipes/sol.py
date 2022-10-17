def solve():
    n, portions, target = map(int, input().split())
    scaling_factor = target / portions

    ingredients = []
    main_weight = 0
    for _ in range(n):
        ingredient, weight, percentage = input().split()
        weight = float(weight)
        percentage = float(percentage)

        if percentage == 100:
            main_weight = weight * scaling_factor

        ingredients.append([ingredient, weight, percentage])

    for ingredient in ingredients:
        ingredient[1] = round(main_weight * ingredient[2] / 100.0, 1)

    return ingredients


if __name__ == "__main__":
    n = int(input())

    for i in range(n):
        scaled = solve()

        print(f"Recipe # {i + 1}")

        for each in scaled:
            print(" ".join([str(x) for x in each[:2]]))

        print("-" * 40)
