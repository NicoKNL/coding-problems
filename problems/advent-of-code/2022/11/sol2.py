import sys
from operator import mul
from functools import reduce


def splitPerMonkey(lines):
    data = []
    monkey = []

    for line in lines:
        if not line:
            data.append(monkey[1:])
            monkey = []
        else:
            monkey.append(line.split(":")[-1].strip())

    if monkey:
        data.append(monkey[1:])

    return data


class Monkey(object):
    def __init__(self, data):
        self.items = list(map(int, data[0].split(",")))
        self.op = self._parseOp(data[1])
        self.mod = int(data[2].split(" ")[-1])
        self.if_true = int(data[3].split(" ")[-1])
        self.if_false = int(data[4].split(" ")[-1])
        self.inspections = 0

    def _parseOp(self, s):
        s = s.split("=")[-1].strip()
        s = s.split(" ")
        return s

    def _applyOp(self, n):
        a = n
        b = n
        if self.op[2] != "old":
            b = int(self.op[2])

        if self.op[1] == "+":
            return a + b
        elif self.op[1] == "*":
            return a * b

    def playRound(self):
        global MONKEYS
        self.inspections += len(self.items)

        for item in self.items:
            worry = self._applyOp(item)

            if worry % self.mod == 0:
                MONKEYS[self.if_true].items.append(worry % MOD)
            else:
                MONKEYS[self.if_false].items.append(worry % MOD)

        self.items = []


if __name__ == "__main__":
    lines = [l.strip() for l in sys.stdin]

    monkey_data = splitPerMonkey(lines)

    MONKEYS = [Monkey(d) for d in monkey_data]
    MOD = reduce(mul, [m.mod for m in MONKEYS])

    for _ in range(10000):
        for m in MONKEYS:
            m.playRound()

    inspections = [m.inspections for m in MONKEYS]
    inspections.sort()

    print(inspections[-2] * inspections[-1])
