class NeighborSum:
    def __init__(self, grid: List[List[int]]):
        self.grid = grid
        self.rows = len(grid)
        self.cols = len(grid[0])

    def _get(self, row: int, col: int) -> int:
        if 0 <= row < self.rows and 0 <= col < self.cols:
            return self.grid[row][col]
        return 0

    def _asRowCol(self, value: int) -> List[int]:
        for r in range(self.rows):
            for c in range(self.cols):
                if self.grid[r][c] == value:
                    return r, c

    def adjacentSum(self, value: int) -> int:
        r, c = self._asRowCol(value)
        fields = [
            self._get(r - 1, c),
            self._get(r + 1, c),
            self._get(r, c - 1),
            self._get(r, c + 1),
        ]
        return sum(fields)

    def diagonalSum(self, value: int) -> int:
        r, c = self._asRowCol(value)
        fields = [
            self._get(r - 1, c - 1),
            self._get(r - 1, c + 1),
            self._get(r + 1, c - 1),
            self._get(r + 1, c + 1),
        ]
        return sum(fields)



# Your NeighborSum object will be instantiated and called as such:
# obj = NeighborSum(grid)
# param_1 = obj.adjacentSum(value)
# param_2 = obj.diagonalSum(value)
