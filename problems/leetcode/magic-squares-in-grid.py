def distinctNumbers(grid: List[List[int]], row: int, col: int) -> bool:
    nums = set()
    for ro in range(3):
        for co in range(3):
            nums.add(grid[row + ro][col + co])

    if len(nums) != 9:
        return False
    
    nums = nums | set([i for i in range(1, 10)])
    return len(nums) == 9



def rowSums(grid: List[List[int]], row: int, col: int) -> bool:
    sums = []
    for ro in range(3):
        rowsum = 0
        for co in range(3):
            rowsum += grid[row + ro][col + co]
        sums.append(rowsum)
    return sums

def colSums(grid: List[List[int]], row: int, col: int) -> bool:
    sums = []
    for co in range(3):
        colsum = 0
        for ro in range(3):
            colsum += grid[row + ro][col + co]
        sums.append(colsum)
    return sums

def diagSumUp(grid: List[List[int]], row: int, col: int) -> bool:
    return grid[row + 2][col] + grid[row + 1][col + 1] + grid[row][col + 2]

def diagSumDown(grid: List[List[int]], row: int, col: int) -> bool:
    return grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2]

def isMagic(grid: List[List[int]], row: int, col: int) -> bool:
    if not distinctNumbers(grid, row, col):
        return False

    rows = rowSums(grid, row, col)
    cols = colSums(grid, row, col)
    diagup = [diagSumUp(grid, row, col)]
    diagdown = [diagSumDown(grid, row, col)]
    
    return len(set(rows + cols + diagup + diagdown)) == 1


class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        count = 0
        for r in range(len(grid) - 2):
            for c in range(len(grid[r]) - 2):
                count += isMagic(grid, r, c)
        return count
