import sys
from string import ascii_lowercase, ascii_uppercase


def getXY(l):
    x = int(l[0].split("=")[-1])
    y = int(l[1].split("=")[-1])
    return x, y


def dist(x1, y1, x2, y2):
    return abs(x1 - x2) + abs(y1 - y2)


class Sensor(object):
    def __init__(self, x1, y1, x2, y2):
        self.x = x1
        self.y = y1
        self.bx = x2
        self.by = y2
        self.dist = dist(x1, y1, x2, y2)


def parseInput(lines):
    sensors = []
    for line in lines:
        line = line.replace(",", "")
        sensor, beacon = line.split(":")
        sensor = getXY(sensor.split()[-2:])
        beacon = getXY(beacon.split()[-2:])
        sensors.append(Sensor(*sensor, *beacon))
    return sensors


def reduce(ranges):
    reduced = True
    while reduced:
        ranges.sort()
        print("> ", ranges)
        reduced = False
        for i in range(len(ranges) - 1):
            r1 = ranges[i]
            r2 = ranges[i + 1]

            if r2[0] <= r1[1]:
                del ranges[i + 1]
                del ranges[i]
                ranges.append((r1[0], max(r1[1], r2[1])))
                reduced = True
                break


if __name__ == "__main__":
    lines = [l.strip() for l in sys.stdin]
    sensors = parseInput(lines)
    print([s.dist for s in sensors])

    GRID = [["." for _ in range(60)] for __ in range(30)]
    OFFSET = 5

    Y = 2000000
    ranges = []
    for i, sensor in enumerate(sensors):
        dy = abs(Y - sensor.y)
        extra_dist = sensor.dist - dy

        if extra_dist >= 0:
            ranges.append((sensor.x - extra_dist, sensor.x + extra_dist))

    print(ranges)
    reduce(ranges)
    print(ranges)
    not_possible = sum([r[1] - r[0] + 1 for r in ranges])

    beacons = set()
    for sensor in sensors:
        if sensor.by == Y:
            print(sensor.x, sensor.y, "->", sensor.bx, sensor.by)
            beacons.add((sensor.bx, sensor.by))
            # GRID[sensor.by][sensor.bx + 5] = "@"
            # not_possible -= 1

    not_possible -= len(beacons)
    # for row in GRID:
    # print("".join(row))
    print(not_possible)
