def char_to_int(c):
    s = "abcdefgh"
    c = c.lower()
    return s.index(c)


if __name__ == "__main__":
    white = input()[7:].split(",")
    black = input()[7:].split(",")

    white = [x for x in white if x]
    black = [x for x in black if x]

    board = []
    for r in range(8):
        row = []

        for c in range(8):
            if r % 2 == 0 and c % 2 == 0:
                row.append(":::")
            if r % 2 == 1 and c % 2 == 0:
                row.append("...")
            if r % 2 == 0 and c % 2 == 1:
                row.append("...")
            if r % 2 == 1 and c % 2 == 1:
                row.append(":::")

        board.append(row)

    for each in white:
        if len(each) == 2:
            each = "P" + each
        else:
            each = each.upper()

        piece = each[0]

        r = int(each[2]) - 1
        c = char_to_int(each[1])

        board[r][c] = board[r][c][:1] + piece + board[r][c][2:]

    for each in black:
        if len(each) == 2:
            each = "p" + each
        else:
            each = each.lower()

        piece = each[0]

        r = int(each[2]) - 1
        c = char_to_int(each[1])

        board[r][c] = board[r][c][:1] + piece + board[r][c][2:]

    for row in reversed(board):
        row = "|".join(row)
        print("+---+---+---+---+---+---+---+---+")
        print(f"|{row}|")

    print("+---+---+---+---+---+---+---+---+")
