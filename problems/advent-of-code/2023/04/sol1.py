import sys


def parseCard(s: str) -> tuple[set[int], set[int]]:
    _, card_data = s.split(":")
    winning_data, my_data = card_data.split("|")

    winning_numbers = [int(num) for num in winning_data.split(" ") if num]

    my_numbers = [int(num) for num in my_data.split(" ") if num]

    return set(winning_numbers), set(my_numbers)


def computeCardValue(winning: set[int], mine: set[int]) -> int:
    overlap = winning.intersection(mine)
    n = len(overlap)

    if n == 0:
        return 0
    else:
        return 2 ** (n - 1)


lines = [line.strip() for line in sys.stdin]

total = 0

for line in lines:
    winning_numbers, my_numbers = parseCard(line)
    total += computeCardValue(winning_numbers, my_numbers)

print(total)
