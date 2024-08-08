class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        row_min = [min(row) for row in matrix]
        col_max = []
        for c in range(len(matrix[0])):
            top = -1
            for r in range(len(matrix)):
                top = max(top, matrix[r][c])
            col_max.append(top)
        
        result = []
        
        for r in range(len(matrix)):
            for c in range(len(matrix[r])):
                if row_min[r] == col_max[c]:
                    result.append(matrix[r][c])
        
        return result
