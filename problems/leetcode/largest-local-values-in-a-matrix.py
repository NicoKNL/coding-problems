class Solution:
    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:
        result = []

        for row in range(1, len(grid) - 1):
            result_row = []
            for col in range(1, len(grid[row]) - 1):
                best = 0
                for ro in [-1, 0, 1]:
                    for co in [-1, 0, 1]:
                        best = max(best, grid[row + ro][col + co])
                result_row.append(best)
            result.append(result_row)
        
        return result
