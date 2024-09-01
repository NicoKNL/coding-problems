def flip(board: List[int], played: List[int]) -> List[int]:
    return [(row ^ (2 ** 3 - 1)) & playrow for (row, playrow) in zip(board, played)]

def containsWin(board: List[int]) -> bool:
    for row in board:
        if row == 2 ** 3 - 1:
            return True
    
    for c in range(3):
        if all([row & (2 ** c) for row in board]):
            return True
    
    crosses = [
        all([board[0] & 2 ** 0, board[1] & 2 ** 1, board[2] & 2 ** 2]),
        all([board[0] & 2 ** 2, board[1] & 2 ** 1, board[2] & 2 ** 0]),
    ]

    return any(crosses)


class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        board = [0, 0, 0]
        played = [0, 0, 0]

        for turn, (r, c) in enumerate(moves):
            board[r] += 2 ** c
            played[r] += 2 ** c

            if containsWin(board):
                return "AB"[turn % 2]

            board = flip(board, played)
        
        if len(moves) == 9:
            return "Draw"

        return "Pending"
