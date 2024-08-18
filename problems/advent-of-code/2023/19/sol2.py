import sys
from copy import deepcopy

Part = dict[str, tuple[int, int]]


class Conditional:
    def __init__(self, key, op, value, redirect):
        self.key = key
        self.op = op
        self.value = value
        self.redirect = redirect

    def isApplicable(self, part: Part) -> bool:
        if self.op == "<":
            return part[self.key][0] < self.value
        else:
            return part[self.key][1] > self.value

    def apply(self, part: Part) -> tuple[Part, Part]:
        part1 = deepcopy(part)
        part2 = deepcopy(part)

        if self.op == "<":
            part1[self.key] = (self.value, part[self.key][1])
            part2[self.key] = (part[self.key][0], self.value - 1)
        else:
            part1[self.key] = (part[self.key][0], self.value)
            part2[self.key] = (self.value + 1, part[self.key][1])

        return part1, part2


class Workflow:
    def __init__(self, description: str):
        self.name, description = description.split("{")
        step_data = description[:-1].split(",")
        self.steps = processSteps(step_data[:-1])
        self.redirect = step_data[-1]

    def apply(self, part: Part) -> tuple[tuple[str, Part], tuple[str, Part]]:
        for step in self.steps:
            if not step.isApplicable(part):
                continue

            reprocess, split = step.apply(part)
            return (self.name, reprocess), (step.redirect, split)

        return (), (self.redirect, part)


def processSteps(steps: list[str]):
    result = []
    for step in steps:
        step, redirect = step.split(":")
        key = step[0]
        operator = step[1]
        value = int(step[2:])
        result.append(Conditional(key, operator, value, redirect))
    return result


def parseWorkflows(lines: list[str]) -> dict[str, Workflow]:
    workflows = dict()

    for line in lines:
        if not line:
            break
        wf = Workflow(line)
        workflows[wf.name] = wf

    return workflows


def computePartCombinations(part: Part) -> int:
    combinations = 1

    for c in "xmas":
        combinations *= part[c][1] - part[c][0] + 1

    return combinations


def processPartsAndWorkflows(initial_part: Part, workflows: dict[str, Workflow]) -> int:
    combinations = 0
    parts = [("in", initial_part)]
    while parts:
        ID, part = parts.pop(0)

        if ID == "A":
            combinations += computePartCombinations(part)
        elif ID != "R":
            wf = workflows[ID]
            part1, part2 = wf.apply(part)

            if part1:
                parts.append(part1)

            if part2:
                parts.append(part2)

    return combinations


lines = [line.strip() for line in sys.stdin]
workflows = parseWorkflows(lines)
initial_part = {"x": (1, 4000), "m": (1, 4000), "a": (1, 4000), "s": (1, 4000)}

total = processPartsAndWorkflows(initial_part, workflows)
print(total)
