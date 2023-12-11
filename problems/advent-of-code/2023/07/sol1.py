import sys
from collections import defaultdict
from enum import Enum


ORDER = "23456789TJQKA"


class HandType(Enum):
    HIGH_CARD = 1
    ONE_PAIR = 2
    TWO_PAIR = 3
    THREE_OF_A_KIND = 4
    FULL_HOUSE = 5
    FOUR_OF_A_KIND = 6
    FIVE_OF_A_KIND = 7


def getCardCounts(cards: str) -> list[str]:
    card_count_dict = defaultdict(int)

    for c in cards:
        card_count_dict[c] += 1

    return list(sorted(card_count_dict.values(), reverse=True))


def determineHandType(cards: str) -> HandType:
    card_counts = getCardCounts(cards)

    if card_counts[0] == 5:
        return HandType.FIVE_OF_A_KIND
    elif card_counts[0] == 4:
        return HandType.FOUR_OF_A_KIND
    elif card_counts[0] == 3 and card_counts[1] == 2:
        return HandType.FULL_HOUSE
    elif card_counts[0] == 3:
        return HandType.THREE_OF_A_KIND
    elif card_counts[0] == 2 and card_counts[1] == 2:
        return HandType.TWO_PAIR
    elif card_counts[0] == 2:
        return HandType.ONE_PAIR
    else:
        return HandType.HIGH_CARD


class Card:
    def __init__(self, value: str):
        self.value = value

    def __eq__(self, other):
        return ORDER.index(self.value) == ORDER.index(other.value)

    def __lt__(self, other):
        return ORDER.index(self.value) < ORDER.index(other.value)


class Hand:
    def __init__(self, cards: str, bid: int):
        self.cards = [Card(c) for c in cards]
        self.bid = bid
        self.hand_type = determineHandType(cards)

    def __lt__(self, other):
        if self.hand_type.value < other.hand_type.value:
            return True
        elif self.hand_type.value == other.hand_type.value:
            for a, b in zip(self.cards, other.cards):
                if a == b:
                    continue
                else:
                    return a < b
        else:
            return False


def getHands(lines: list[str]) -> list[Hand]:
    hands = []

    for line in lines:
        cards, bid = line.split(" ")
        hands.append(Hand(cards, int(bid)))

    return hands


lines = [line.strip() for line in sys.stdin]

hands = getHands(lines)
hands = sorted(hands)

total = 0

for i, hand in enumerate(hands, 1):
    total += hand.bid * i

print(total)
