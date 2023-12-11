import sys
from math import sqrt, floor, ceil
import re


def getNumber(s: str) -> list[int]:
    s = s.replace(" ", "")
    pattern = r"\d+"
    data = re.findall(pattern, s)
    return list(map(int, data))[0]


def raceWithBruteForce(time_limit: int, target_distance: int) -> int:
    wins = 0

    for hold_time in range(time_limit):
        speed = hold_time
        race_time = time_limit - hold_time
        race_distance = race_time * speed

        if race_distance > target_distance:
            wins += 1

    return wins


def raceWithEquation(time: int, target_distance: int) -> int:
    a = -1
    b = time
    c = -(target_distance + 1e-9)  # Add one nanometer

    discriminant = b * b - 4 * a * c

    x1 = (-b + sqrt(discriminant)) / 2 * a
    x2 = (-b - sqrt(discriminant)) / 2 * a

    left = int(floor(x1))
    right = int(ceil(x2))

    return right - left - 1


lines = [line.strip() for line in sys.stdin]


time = getNumber(lines[0])
distance = getNumber(lines[1])

print(raceWithEquation(time, distance))
