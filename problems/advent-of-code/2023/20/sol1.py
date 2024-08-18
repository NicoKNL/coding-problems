import sys
from enum import Enum
from collections import defaultdict


LO = False
HI = True


class ComponentType(Enum):
    UNKNOWN = 0
    BROADCASTER = 1
    FLIPFLOP = 2
    CONJUNCTION = 3


def parseInput(lines: list[str]) -> None:
    for line in lines:
        line = line.replace(" ", "")
        from_, to_ = line.split("->")
        to_ = to_.split(",")

        if from_.startswith("broadcaster"):
            TYPE[from_] = ComponentType.BROADCASTER
        else:
            t = from_[0]
            from_ = from_[1:]
            if t == "%":
                TYPE[from_] = ComponentType.FLIPFLOP

            if t == "&":
                TYPE[from_] = ComponentType.CONJUNCTION

        CHILDREN[from_] = to_
        STATE[from_] = LO


def connectParents() -> None:
    for name, connections in CHILDREN.items():
        for connection in connections:
            PARENTS[connection].append(name)


def broadcast(node: str) -> list[tuple[str, bool]]:
    STATE[node] = LO
    return [(child, False) for child in CHILDREN[node]]


def flipflop(node: str) -> list[tuple[str, bool]]:
    STATE[node] = not STATE[node]
    return [(child, STATE[node]) for child in CHILDREN[node]]


def conjunct(node: str) -> list[tuple[str, bool]]:
    parent_states_all_high = all(STATE[p] == HI for p in PARENTS[node])
    if parent_states_all_high:
        STATE[node] = LO
    else:
        STATE[node] = HI

    return [(child, STATE[node]) for child in CHILDREN[node]]


def pushButton() -> tuple[int, int]:
    low = 0
    high = 0
    Q = [("broadcaster", LO)]

    while Q:
        node, pulse = Q.pop(0)
        node_type = TYPE[node]

        low += 1 - pulse
        high += pulse

        if node_type == ComponentType.BROADCASTER:
            Q.extend(broadcast(node))

        if node_type == ComponentType.FLIPFLOP:
            if pulse == False:
                Q.extend(flipflop(node))

        if node_type == ComponentType.CONJUNCTION:
            Q.extend(conjunct(node))

    return low, high


STATE = defaultdict(bool)
TYPE = defaultdict(lambda: ComponentType.UNKNOWN)
CHILDREN = defaultdict(list)
PARENTS = defaultdict(list)

lines = [line.strip() for line in sys.stdin]
parseInput(lines)
connectParents()

pulses_low = 0
pulses_high = 0

for _ in range(1000):
    lo, hi = pushButton()
    pulses_low += lo
    pulses_high += hi

print(pulses_low * pulses_high)
