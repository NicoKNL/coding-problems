class SubrectangleQueries:

    def __init__(self, rectangle: List[List[int]]):
        self.rectangle = rectangle
        self.overwrites = []

    def updateSubrectangle(self, row1: int, col1: int, row2: int, col2: int, newValue: int) -> None:
        self.overwrites.append(((row1, col1, row2, col2), newValue))

    def getValue(self, row: int, col: int) -> int:
        ans = -1
        for ((r1, c1, r2, c2), value) in self.overwrites:
            if r1 <= row <= r2 and c1 <= col <= c2:
                ans = value
        
        if ans == -1:
            return self.rectangle[row][col]
        else:
            return ans


# Your SubrectangleQueries object will be instantiated and called as such:
# obj = SubrectangleQueries(rectangle)
# obj.updateSubrectangle(row1,col1,row2,col2,newValue)
# param_2 = obj.getValue(row,col)
