from math import ceil


def breakEvenDay(cost, profit):
    return ceil(cost / profit)


def daysUntilMoney(money, investment):
    return ceil((money + investment.cost) / investment.profit)


class Investment:
    def __init__(self, profit, cost):
        self.profit = profit
        self.cost = cost
        self.day = 0

    def __repr__(self):
        return f"{self.profit} - {self.cost} - {self.day}"


if __name__ == "__main__":
    n, money = map(int, input().split())

    investments = []

    for i in range(n):
        profit, cost = map(int, input().split())
        investments.append(Investment(profit, cost))
        investments[-1].day = breakEvenDay(cost, profit)

    investments.sort(key=lambda x: x.day)

    inv = investments[0]
    days = daysUntilMoney(money, inv)

    for i in range(1, len(investments)):
        other = investments[i]

        if other.day > days:
            break

        new_inv = Investment(inv.profit + other.profit, inv.cost + other.cost)
        days_with_new_inv = daysUntilMoney(money, new_inv)

        if days_with_new_inv <= days:
            inv = new_inv
            days = days_with_new_inv

    print(days)
