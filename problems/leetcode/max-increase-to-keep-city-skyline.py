def rot90(l):
    return [list(reversed(x)) for x in zip(*l)]

class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        max_row = [max(row) for row in grid]
        max_col = [max(row) for row in rot90(grid)]

        total = 0
        for r in range(len(grid)):
            for c in range(len(grid[r])):
                total += min(max_row[r], max_col[c]) - grid[r][c]
        
        return total
