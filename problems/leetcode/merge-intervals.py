class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        result = [intervals[0]]

        for start, end in intervals[1:]:
            if result[-1][0] <= start <= result[-1][-1]:
                result[-1] = (result[-1][0], max(result[-1][-1], end))
            else:
                result.append((start, end))

        return result
