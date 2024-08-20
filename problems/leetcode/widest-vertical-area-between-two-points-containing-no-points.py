class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        points = sorted(points)

        best = points[1][0] - points[0][0]
        for i in range(2, len(points)):
            best = max(best, points[i][0] - points[i - 1][0])

        return best
