import sys


def parseCard(s: str) -> tuple[set[int], set[int]]:
    _, card_data = s.split(":")
    winning_data, my_data = card_data.split("|")
    winning_numbers = [int(num) for num in winning_data.split(" ") if num]
    my_numbers = [int(num) for num in my_data.split(" ") if num]

    return set(winning_numbers), set(my_numbers)


def computeCardValue(winning: set[int], mine: set[int]) -> int:
    overlap = winning.intersection(mine)
    return len(overlap)


def obtainNextCards(
    card_count: list[int], cards: dict[int, tuple[set[int], set[int]]]
) -> list[int]:
    next_card_count = [0 for _ in range(len(cards))]

    for i, card_data in cards.items():  # (winning_numbers, my_numbers)
        if card_count[i]:
            value = computeCardValue(*card_data)

            for ii in range(i + 1, i + value + 1):
                next_card_count[ii] += card_count[i]

    return next_card_count


def simulateCardGame(cards: dict[int, tuple[set[int], set[int]]]) -> int:
    card_count = [1 for _ in range(len(cards))]

    new_cards = sum(card_count)
    total = new_cards

    while new_cards:
        next_card_count = obtainNextCards(card_count, cards)

        new_cards = sum(next_card_count)
        total += new_cards

        card_count = next_card_count

    return total


lines = [line.strip() for line in sys.stdin]

cards = dict()

for i, line in enumerate(lines):
    cards[i] = parseCard(line)  # (winning_numbers, my_numbers)

print(simulateCardGame(cards))
