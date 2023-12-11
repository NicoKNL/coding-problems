import sys
import re
from math import lcm


def parseNodes(lines: list[str]) -> dict[str, tuple[str, str]]:
    pattern = r"[A-Z]{3}"

    nodes = {}
    for line in lines:
        label, left, right = re.findall(pattern, line)
        nodes[label] = (left, right)

    return nodes


def traverse(node: str) -> int:
    steps = 0

    while not node.endswith("Z"):
        if directions[steps % len(directions)] == "L":
            node = nodes[node][0]
        else:
            node = nodes[node][1]

        steps += 1

    return steps


lines = [line.strip() for line in sys.stdin]

directions = lines[0]
nodes = parseNodes(lines[2:])
A_nodes = [n for n in nodes.keys() if n.endswith("A")]
cycle_lengths = [traverse(n) for n in A_nodes]

print(lcm(*cycle_lengths))
