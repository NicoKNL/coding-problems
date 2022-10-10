from math import isclose


def printUnit(unit):
    print(f"{unit.cost} {unit.health} {unit.potency}")


def calculate_gain(unit1, unit2, budget, split):
    x = split
    y = budget - split

    x_units = x / unit1.cost
    y_units = y / unit2.cost

    total_health = (x_units * unit1.health) + (y_units * unit2.health)
    total_potency = (x_units * unit1.potency) + (y_units * unit2.potency)

    gain = total_health * total_potency

    return gain


def search(unit1, unit2, budget, tolerance):
    left = 0
    right = budget

    while abs(right - left) >= tolerance:
        left_third = left + (right - left) / 3
        right_third = right - (right - left) / 3

        if calculate_gain(unit1, unit2, budget, left_third) > calculate_gain(
            unit1, unit2, budget, right_third
        ):
            right = right_third
        else:
            left = left_third

    return calculate_gain(unit1, unit2, budget, (left + right) / 2)


class Unit:
    def __init__(self, cost, health, potency):
        self.cost = cost
        self.health = health
        self.potency = potency


def solve():
    n, budget = map(int, input().split())

    unit1 = None
    unit2 = None
    best_result = -1
    for _ in range(n):
        # print(_)
        cost, health, potency = map(float, input().split())
        unit = Unit(cost, health, potency)

        if not unit1:
            unit1 = unit
            continue

        if not unit2:
            unit2 = unit
            best_result = search(unit1, unit2, budget, 0.0001)
            continue

        option1 = [unit1, unit]
        option1_result = search(option1[0], option1[1], budget, 0.0001)

        option2 = [unit, unit2]
        option2_result = search(option2[0], option2[1], budget, 0.0001)

        best_alternative = None
        bets_alternative_result = -1
        if option1_result > option2_result:
            best_alternative = option1
            bets_alternative_result = option1_result
        else:
            best_alternative = option2
            bets_alternative_result = option2_result

        if bets_alternative_result > best_result:
            unit1, unit2 = best_alternative

    if not unit2:
        unit2 = unit1
    # printUnit(unit1)
    # printUnit(unit2)
    print(search(unit1, unit2, budget, 0.00001))


if __name__ == "__main__":
    solve()
