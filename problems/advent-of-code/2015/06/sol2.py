import sys

GRID = [[0 for _ in range(1000)] for __ in range(1000)]


def turn(state, corner1, corner2):
    for r in range(corner1[1], corner2[1] + 1):
        for c in range(corner1[0], corner2[0] + 1):
            if state:
                GRID[r][c] += 1
            else:
                GRID[r][c] -= 1
                if GRID[r][c] < 0:
                    GRID[r][c] = 0


def toggle(corner1, corner2):
    for r in range(corner1[1], corner2[1] + 1):
        for c in range(corner1[0], corner2[0] + 1):
            GRID[r][c] += 2


def strToCoordinate(s):
    return list(map(int, s.split(",")))


if __name__ == "__main__":
    lines = [l.strip() for l in sys.stdin]

    for line in lines:
        instr = line.split()

        if instr[1] == "on" or instr[1] == "off":
            corner1 = strToCoordinate(instr[2])
            corner2 = strToCoordinate(instr[4])
        else:
            corner1 = strToCoordinate(instr[1])
            corner2 = strToCoordinate(instr[3])

        if instr[1] == "on":
            turn(True, corner1, corner2)
        elif instr[1] == "off":
            turn(False, corner1, corner2)
        else:
            toggle(corner1, corner2)

    print(sum([sum(r) for r in GRID]))
