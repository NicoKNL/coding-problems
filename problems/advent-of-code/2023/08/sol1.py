import sys
import re


def parseNodes(lines: list[str]) -> dict[str, tuple[str, str]]:
    pattern = r"[A-Z]{3}"

    nodes = {}
    for line in lines:
        label, left, right = re.findall(pattern, line)
        nodes[label] = (left, right)

    return nodes


def traverse() -> int:
    node = "AAA"
    steps = 0
    while node != "ZZZ":
        if directions[steps % len(directions)] == "L":
            node = nodes[node][0]
        else:
            node = nodes[node][1]

        steps += 1

    return steps


lines = [line.strip() for line in sys.stdin]

directions = lines[0]
nodes = parseNodes(lines[2:])
steps = traverse()

print(steps)
