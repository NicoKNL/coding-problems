import sys
from math import sqrt, floor, ceil
import re


def getNumbers(s: str) -> list[int]:
    pattern = r"\d+"
    data = re.findall(pattern, s)
    return list(map(int, data))


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
    # When is (-1 * x^2 + time * x) > target_distance?
    # If: ax^2 + bx + c = 0
    # Then: discriminant = b^2 - 4 * a * c
    #       x1 = (-b - sqrt(discriminant)) / 2a
    #       x2 = (-b + sqrt(discriminant)) / 2a
    a = -1
    b = time
    c = -(target_distance + 1e9)

    discriminant = b * b - 4 * a * c

    x1 = (-b + sqrt(discriminant)) / 2 * a
    x2 = (-b - sqrt(discriminant)) / 2 * a

    left = int(floor(x1))
    right = int(ceil(x2))

    return right - left - 1


lines = [line.strip() for line in sys.stdin]


times = getNumbers(lines[0])
distances = getNumbers(lines[1])

total = 1

for i in range(len(times)):
    total *= raceWithBruteForce(times[i], distances[i])

print(total)
