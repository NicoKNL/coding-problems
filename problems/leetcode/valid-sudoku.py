def rowOrColIsValid(row: List[str]) -> bool:
    count = 0
    S = set()
    for c in row:
        if c != ".":
            count += 1
            S.add(c)
    return count == len(S)

def subBoxIsValid(board: List[List[str]], row: int, col: int) -> bool:
    idx = [0, 0, 0, 1, 1, 1, 2, 2, 2]
    box_r = idx[row]
    box_c = idx[col]

    subbox = []
    for r in range(box_r * 3, (box_r + 1) * 3):
        for c in range(box_c * 3, (box_c + 1) * 3):
            subbox.append(board[r][c])
    
    return rowOrColIsValid(subbox)

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for r in range(len(board)):
            for c in range(len(board[r])):
                if board[r][c] == ".":
                    continue

                if not rowOrColIsValid(board[r]):
                    return False
                
                if not rowOrColIsValid([board[i][c] for i in range(len(board))]):
                    return False

                if not subBoxIsValid(board, r, c):
                    return False


        return True
