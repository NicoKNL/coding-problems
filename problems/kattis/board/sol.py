BOARD = None
ROWS = 0
COLS = 0
COUNT = 0
OFFSET = [0, 1, 2]


def unpaint(r, c):
    global COUNT
    for ro in OFFSET:
        for co in OFFSET:
            if BOARD[r + ro][c + co] != "*":
                COUNT -= 1
                BOARD[r + ro][c + co] = "*"


def isGrid(r, c):
    colors = set()
    for ro in OFFSET:
        for co in OFFSET:
            color = BOARD[r + ro][c + co]
            if color == "W":
                return False
            elif color != "*":
                colors.add(color)
                if len(colors) > 1:
                    return False

    return colors


def reduce():
    for r in range(ROWS - 2):
        for c in range(COLS - 2):
            if isGrid(r, c):
                unpaint(r, c)
                return True
    return False


if __name__ == "__main__":
    ROWS, COLS = map(int, input().split())

    BOARD = []
    for _ in range(ROWS):
        row = list(input())
        BOARD.append(row)

    COUNT = 0
    for r in range(ROWS):
        for c in range(COLS):
            if BOARD[r][c] != "W":
                COUNT += 1

    while COUNT > 0:
        if not reduce():
            break

    if COUNT > 0:
        print("NO")
    else:
        print("YES")
