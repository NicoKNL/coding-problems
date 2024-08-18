import sys

Part = dict[str, int]

from operator import lt, gt

OPERATORS = {
    "<": lt,
    ">": gt,
}


class Conditional:
    def __init__(self, key, op, value, redirect):
        self.key = key
        self.op = op
        self.value = value
        self.redirect = redirect

    def apply(self, part: Part) -> bool:
        return self.op(part[self.key], self.value)


class Workflow:
    def __init__(self, description: str):
        self.name, description = description.split("{")
        step_data = description[:-1].split(",")
        self.steps = processSteps(step_data[:-1])
        self.redirect = step_data[-1]

    def apply(self, part: Part) -> str:
        for step in self.steps:
            if step.apply(part):
                return step.redirect

        return self.redirect


def processSteps(steps: list[str]) -> list[Conditional]:
    result = []

    for step in steps:
        step, redirect = step.split(":")
        key = step[0]
        operator = OPERATORS[step[1]]
        value = int(step[2:])
        result.append(Conditional(key, operator, value, redirect))

    return result


def parseParts(lines: list[str]) -> list[Part]:
    parts = []
    for line in lines:
        segments = line[1:-1].split(",")
        parts.append(
            {
                "x": int(segments[0].split("=")[-1]),
                "m": int(segments[1].split("=")[-1]),
                "a": int(segments[2].split("=")[-1]),
                "s": int(segments[3].split("=")[-1]),
            }
        )

    return parts


def parseWorkflows(lines: list[str]) -> dict[str, Workflow]:
    workflows = dict()

    for line in lines:
        wf = Workflow(line)
        workflows[wf.name] = wf

    return workflows


def parseInput(lines: list[str]) -> tuple[dict[str, Workflow], list[Part]]:
    empty_line = lines.index("")

    workflows = parseWorkflows(lines[:empty_line])
    parts = parseParts(lines[empty_line + 1 :])

    return workflows, parts


def isAccepted(part: Part) -> bool:
    ID = "in"

    while ID not in ["R", "A"]:
        wf = workflows[ID]
        ID = wf.apply(part)

    return ID == "A"


lines = [line.strip() for line in sys.stdin]
workflows, parts = parseInput(lines)

total = 0
for part in parts:
    if isAccepted(part):
        total += sum(part.values())

print(total)
