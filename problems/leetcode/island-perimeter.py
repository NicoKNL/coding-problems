def countCrossings(grid: List[List[int]]) -> int:
    total = 0
    for r in range(len(grid)):
        crossings = 0
        out = True
        for c in range(len(grid[r])):
            if grid[r][c] and out:
                crossings += 1
                out = False
            elif not grid[r][c] and not out:
                crossings += 1
                out = True

        if not out:
            crossings += 1

        total += crossings
    return total

class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        boundary = countCrossings(grid)
        boundary += countCrossings(list(zip(*grid[::-1])))
        return boundary
