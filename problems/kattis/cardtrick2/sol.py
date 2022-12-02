from collections import deque


if __name__ == "__main__":
    T = int(input())

    for _ in range(T):
        n = int(input())

        cards = deque()
        card = n
        while card > 0:
            cards.appendleft(card)
            cards.rotate(card)
            card -= 1

        print(" ".join(map(str, cards)))
