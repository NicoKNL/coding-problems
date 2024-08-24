class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        next_board = [[0 for _ in range(len(board[0]))] for __ in range(len(board))]
        for r in range(len(board)):
            for c in range(len(board[0])):
                if board[r][c] == 1:
                    for ro in [-1, 0, 1]:
                        for co in [-1, 0, 1]:
                            if ro == 0 and co == 0:
                                continue
                            
                            if 0 <= r + ro < len(board):
                                if 0 <= c + co < len(board[0]):
                                    next_board[r + ro][c + co] += 1
        
        for r in range(len(board)):
            for c in range(len(board[0])):
                if board[r][c] == 0:
                    if next_board[r][c] == 3:
                        board[r][c] = 1
                else:
                    board[r][c] = 0
                    if 2 <= next_board[r][c] <= 3:
                        board[r][c] = 1
