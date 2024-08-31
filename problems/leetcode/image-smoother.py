from math import floor
from itertools import product

def emptyGrid(grid: List[List[int]]) -> List[List[int]]:
    return [[0 for _ in range(len(grid[0]))] for __ in range(len(grid))]


def isInBounds(row: int, column: int, rows: int, columns: int) -> bool:
    return 0 <= row < rows and 0 <= column < columns

def imgCount(img: List[List[int]]) -> List[List[int]]:
    result = emptyGrid(img)

    ROWS = len(img)
    COLS = len(img[0])

    offsets = [-1, 0, 1]
    for r in range(len(img)):
        for c in range(len(img[r])):
            for (ro, co) in product(offsets, repeat=2):
                if isInBounds(r + ro, c + co, ROWS, COLS):
                    result[r + ro][c + co] += 1
    
    return result

def imgSum(img: List[List[int]]) -> List[List[int]]:
    result = emptyGrid(img)

    ROWS = len(img)
    COLS = len(img[0])

    offsets = [-1, 0, 1]
    for r in range(len(img)):
        for c in range(len(img[r])):
            for (ro, co) in product(offsets, repeat=2):
                if isInBounds(r + ro, c + co, ROWS, COLS):
                    result[r + ro][c + co] += img[r][c]
    
    return result

class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        count = imgCount(img)
        weight = imgSum(img)

        result = emptyGrid(img)
        for r in range(len(img)):
            for c in range(len(img[r])):
                result[r][c] = int(floor(weight[r][c] / count[r][c]))
        
        return result
