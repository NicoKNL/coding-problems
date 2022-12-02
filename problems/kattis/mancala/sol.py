SOLUTIONS = [[0]]


def build_solutions():
    board = [0]
    counter = 1
    while len(board) <= 80:
        counter += 1
        count = 1
        for i in range(len(board)):
            if i == 0:
                continue
            if board[i] + count == i:
                board[i] += count
                count = 0
                SOLUTIONS.append(board.copy())
                break
            else:
                if board[i]:
                    count += 1
                    board[i] -= 1

        if count:
            board.append(count)
            SOLUTIONS.append(board.copy())


def solve():
    k, n = map(int, input().split())

    sol = SOLUTIONS[n][1:]
    print(k, len(sol))
    for i in range(0, len(sol), 10):
        print(" ".join(map(str, sol[i : i + 10])))


if __name__ == "__main__":
    build_solutions()

    n = int(input())

    for _ in range(n):
        solve()
