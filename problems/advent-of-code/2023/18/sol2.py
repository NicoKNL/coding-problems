import sys

Vec2 = tuple[int, int]

UP = (-1, 0)
DOWN = (1, 0)
LEFT = (0, -1)
RIGHT = (0, 1)

OFFSET = {
    "U": UP,
    "D": DOWN,
    "L": LEFT,
    "R": RIGHT,
}

TRANSLATE = ["R", "D", "L", "U"]


def add(a: Vec2, b: Vec2) -> Vec2:
    return (a[0] + b[0], a[1] + b[1])


def mul(a: Vec2, b: int) -> Vec2:
    return (b * a[0], b * a[1])


def parseInput() -> list[Vec2]:
    plan = []

    for line in sys.stdin:
        _, hexstring = line.strip().split("#")
        steps = int(hexstring[:5], 16)

        offset = mul(OFFSET[TRANSLATE[int(hexstring[-2])]], int(steps))
        plan.append(offset)

    return plan


def determineCorners(plan: list[Vec2]) -> list[Vec2]:
    corners = list()
    pos = (0, 0)
    corners.append(pos)

    for offset in plan:
        pos = add(pos, offset)
        corners.append(pos)

    return corners


def computeBorderArea(plan: list[Vec2]) -> int:
    border_area = 0

    for direction in plan:
        border_area += abs(direction[0])
        border_area += abs(direction[1])

    return border_area


def shoelace(plan: list[Vec2]) -> int:
    corners = determineCorners(plan)

    all_x = [pos[0] for pos in corners]
    all_y = [pos[1] for pos in corners]

    total = 0
    for x, y in zip(all_x, all_y[1:]):
        total += x * y

    for x, y in zip(all_x[1:], all_y):
        total -= x * y

    return abs(total) // 2


plan = parseInput()
border_area = computeBorderArea(plan)
inner_area = shoelace(plan)

corrected_border = (border_area - 4) // 2 + 3

print(inner_area + corrected_border)
