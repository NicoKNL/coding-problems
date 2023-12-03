import sys
import re


def getNumber(s: str) -> int:
    pattern = r"\d+"
    return int(re.search(pattern, s)[0])


def getColor(s: str) -> str:
    pattern = r"(red|green|blue)"
    return re.search(pattern, s)[0]


def parseLine(s: str) -> tuple[int, list[dict[str, int]]]:
    game, data = s.split(":")
    game_number = getNumber(game)

    chunks = data.split(";")
    samples = []

    for chunk in chunks:
        values = {"red": 0, "blue": 0, "green": 0}
        parts = chunk.split(",")
        for part in parts:
            values[getColor(part)] = getNumber(part)
        samples.append(values)

    return game_number, samples


def isValidGame(samples: list[dict[str, int]]) -> bool:
    for sample in samples:
        if sample["red"] > 12 or sample["green"] > 13 or sample["blue"] > 14:
            return False
    return True


lines = [line.strip() for line in sys.stdin]

total = 0

for line in lines:
    game_number, samples = parseLine(line)
    if isValidGame(samples):
        total += game_number

print(total)
