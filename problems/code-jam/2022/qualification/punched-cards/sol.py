def printCard(card):
    for row in card:
        print(row)


def solve():
    nrows, ncols = map(int, input().split())

    border = "+" + "-+" * ncols
    row = "|" + ".|" * ncols

    card = [border]

    for r in range(nrows):
        card.append(row)
        card.append(border)

    card[0] = ".." + card[0][2:]
    card[1] = "." + card[1][1:]
    printCard(card)


if __name__ == "__main__":
    T = int(input())

    for i in range(1, T + 1):
        print(f"Case #{i}:")
        solve()
