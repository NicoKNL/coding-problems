class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        height = len(matrix)
        for c in range(-(height - 1), len(matrix[0])):
            S = set()
            for r in range(len(matrix)):
                if 0 <= c + r < len(matrix[0]):
                    S.add(matrix[r][c + r])
            
            if len(S) > 1:
                return False
        
        return True
