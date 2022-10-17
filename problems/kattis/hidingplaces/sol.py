from math import inf

jumps = [
    [-2, -1],
    [-1, -2],
    [2, 1],
    [1, 2],
    [-1, 2],
    [-2, 1],
    [2, -1],
    [1, -2],
]


def is_in_board(r, c, ro, co):
    return 0 <= r + ro < 8 and 0 <= c + co < 8


def recurse(board):
    changes = False

    for r in range(8):
        for c in range(8):
            dist = board[r][c]
            if dist < inf:
                for jump in jumps:
                    if is_in_board(r, c, *jump):
                        if board[r][c] + 1 < board[r + jump[0]][c + jump[1]]:
                            changes = True
                            board[r + jump[0]][c + jump[1]] = board[r][c] + 1

    return changes


ABCDEFGH = "abcdefgh"


def solve():
    s = input()
    row = ABCDEFGH.index(s[0])
    col = int(s[1]) - 1

    board = [[inf for col in range(8)] for row in range(8)]
    board[row][col] = 0

    changes = recurse(board)
    while changes:
        changes = recurse(board)

    results = []
    current = 0
    for r in range(8):
        for c in range(8):
            if board[r][c] > current:
                results = [f"{ABCDEFGH[r]}{c + 1}"]
                current = board[r][c]
            elif board[r][c] == current:
                results.append(f"{ABCDEFGH[r]}{c + 1}")

    results.sort()
    results.sort(key=lambda x: x[1], reverse=True)
    print(current, " ".join(results))


if __name__ == "__main__":
    N = int(input())

    for _ in range(N):
        solve()
