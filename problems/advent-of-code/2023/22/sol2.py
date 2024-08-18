import sys
from collections import defaultdict

Vec3 = tuple[int, int, int]
Brick = tuple[Vec3, Vec3]


def asVec3(s: str) -> Vec3:
    return tuple(map(int, s.split(",")))


def parseBricks(lines: list[str]) -> list[Brick]:
    bricks = []

    for line in lines:
        a, b = line.split("~")
        bricks.append((asVec3(a), asVec3(b)))

    return bricks


def getBlocks(brick: Brick) -> list[Vec3]:
    blocks = []
    for x in range(brick[0][0], brick[1][0] + 1):
        for y in range(brick[0][1], brick[1][1] + 1):
            for z in range(brick[0][2], brick[1][2] + 1):
                blocks.append((x, y, z))
    return blocks


def blockIsInBrick(block: Vec3, brick: Brick) -> bool:
    x, y, z = block
    xmin, ymin, zmin = brick[0]
    xmax, ymax, zmax = brick[1]

    return xmin <= x <= xmax and ymin <= y <= ymax and zmin <= z <= zmax


def isSupporting(top_brick: Brick, bottom_brick: Brick) -> bool:
    # print(f"Does {bottom_brick} support {top_brick}?")
    for block in getBlocks(top_brick):
        support_block = (block[0], block[1], block[2] - 1)

        if blockIsInBrick(support_block, bottom_brick):
            # print("yes", support_block)
            return True

    # print("no")
    return False


def stackBricks(bricks: list[Brick]) -> tuple[int, list[Brick]]:
    top_level = defaultdict(int)
    stacked_bricks = []
    falling_bricks = 0

    for brick in bricks:
        xmin, ymin, zmin = brick[0]
        xmax, ymax, zmax = brick[1]

        shift_down = 10e9
        for x in range(xmin, xmax + 1):
            for y in range(ymin, ymax + 1):
                z_offset = zmin - top_level[(x, y)]
                shift_down = min(shift_down, z_offset)

        for x in range(xmin, xmax + 1):
            for y in range(ymin, ymax + 1):
                top_level[(x, y)] = zmax - shift_down + 1

        if shift_down > 1:
            falling_bricks += 1

        stacked_bricks.append(
            (
                (xmin, ymin, zmin - shift_down + 1),
                (xmax, ymax, zmax - shift_down + 1),
            )
        )
        # print(top_level)

    return falling_bricks, stacked_bricks


lines = [line.strip() for line in sys.stdin]
bricks = parseBricks(lines)
bricks = list(sorted(bricks, key=lambda brick: brick[0][2]))
print("---" * 100)
for brick in bricks:
    print(brick)
print("---" * 100)
falling, bricks = stackBricks(bricks)
print("falling: ", falling)
print("---" * 100)
for brick in bricks:
    print(brick)
print("---" * 100)
falling, bricks = stackBricks(bricks)
print("falling: ", falling)
print("---" * 100)
for brick in bricks:
    print(brick)
print("---" * 100)

supports = {brick: [] for brick in bricks}
supported_by = {brick: [] for brick in bricks}
support_count = {brick: 0 for brick in bricks}
for top_brick in bricks:
    for bottom_brick in bricks:
        if top_brick == bottom_brick:
            continue

        if isSupporting(top_brick, bottom_brick):
            supports[bottom_brick].append(top_brick)
            supported_by[top_brick].append(bottom_brick)

count = 0
for brick in reversed(bricks):
    other_bricks = supports[brick]
    print("brick: ", brick)
    deletable = True
    for other in other_bricks:
        if len(supported_by[other]) == 1:
            deletable = False
        # support_count[brick] += support_count[other]

    if not deletable:
        new_bricks = [b for b in bricks if b != brick]
        falling_bricks, _ = stackBricks(new_bricks)
        count += falling_bricks


print(count)
print(sum(support_count.values()))
