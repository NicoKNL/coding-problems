import sys
from enum import Enum
from collections import defaultdict
from math import lcm


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


def conjunct(node: str, presses: int) -> list[tuple[str, bool]]:
    parent_states_all_high = all(STATE[p] == HI for p in PARENTS[node])
    if parent_states_all_high:
        CYCLES[node] = presses
        STATE[node] = LO
    else:
        STATE[node] = HI

    return [(child, STATE[node]) for child in CHILDREN[node]]


def getConjunctions(root: str, depth: int, target_depth: int) -> list[str]:
    if depth == target_depth:
        return [p for p in PARENTS[root] if TYPE[p] == ComponentType.CONJUNCTION]

    conjunctions = []
    for p in PARENTS[root]:
        conjunctions.extend(getConjunctions(p, depth + 1, target_depth))

    return conjunctions


def keyConjunctionsMissing(nodes: list[str]) -> bool:
    return any(CYCLES[n] == 0 for n in nodes)


def pushButton(presses: int) -> None:
    Q = [("broadcaster", LO)]

    while Q:
        node, pulse = Q.pop(0)
        node_type = TYPE[node]

        if node_type == ComponentType.BROADCASTER:
            Q.extend(broadcast(node))

        if node_type == ComponentType.FLIPFLOP:
            if pulse == False:
                Q.extend(flipflop(node))

        if node_type == ComponentType.CONJUNCTION:
            Q.extend(conjunct(node, presses))


STATE = defaultdict(bool)
TYPE = defaultdict(lambda: ComponentType.UNKNOWN)
CHILDREN = defaultdict(list)
PARENTS = defaultdict(list)
CYCLES = defaultdict(int)

lines = [line.strip() for line in sys.stdin]
parseInput(lines)
connectParents()

presses = 0
key_nodes = getConjunctions("rx", 0, 2)

while keyConjunctionsMissing(key_nodes):
    presses += 1
    pushButton(presses)

cycle_length = lcm(*[CYCLES[node] for node in getConjunctions("rx", 0, 2)])
print(cycle_length)
