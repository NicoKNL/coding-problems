class Solution:
    def maxCount(self, m: int, n: int, ops: List[List[int]]) -> int:
        minx, miny = m, n

        for x, y in ops:
            minx = min(minx, x)
            miny = min(miny, y)

        return minx * miny
