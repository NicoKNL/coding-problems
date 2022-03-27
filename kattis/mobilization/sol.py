from math import isclose


def solve2():
    n, budget = map(int, input().split())

    max_efficacy = -1

    for _ in range(n):
        cost, health, potency = map(float, input().split())

        units = budget / cost
        total_health = units * health
        total_potency = units * potency
        efficacy = total_health * total_potency

        print("units: ", units)
        print("efficacy: ", efficacy)

        max_efficacy = max(efficacy, max_efficacy)

    print(max_efficacy)


def printUnit(unit):
    print(f"{unit.cost} {unit.health} {unit.potency}")


def search(unit1, unit2, budget, tolerance):
    x = 0

    scan_up = True
    prev_gain = -1
    step = 1000
    while True:
        if x > budget:
            x = budget
            step /= 2
            x -= step
            scan_up = False

        if x < 0:
            x = 0
            step /= 2
            x += step
            scan_up = True

        y = budget - x

        x_units = x / unit1.cost
        y_units = y / unit2.cost

        total_health = (x_units * unit1.health) + (y_units * unit2.health)
        total_potency = (x_units * unit1.potency) + (y_units * unit2.potency)

        gain = total_health * total_potency

        if isclose(prev_gain, gain, abs_tol=tolerance):
            return gain

        if gain < prev_gain:
            # print("swap")
            step /= 2
            scan_up = not scan_up
            # print(step, scan_up)
        # print(x, gain)
        prev_gain = gain

        if scan_up:
            x += step
        else:
            x -= step


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
            best_result = search(unit1, unit2, 10000, 0.0001)
            continue

        option1 = [unit1, unit]
        option1_result = search(option1[0], option1[1], 10000, 0.0001)

        option2 = [unit, unit2]
        option2_result = search(option2[0], option2[1], 10000, 0.0001)

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

    # printUnit(unit1)
    # printUnit(unit2)
    # print("final search")
    print(search(unit1, unit2, budget, 0.00001))


if __name__ == "__main__":
    solve()
