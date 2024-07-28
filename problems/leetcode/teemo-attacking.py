def mergeIntervals(intervals: List[Tuple[int, int]]) -> List[Tuple[int, int]]:
    intervals.sort()
    result = [intervals[0]]

    for start, end in intervals[1:]:
        if result[-1][0] <= start <= result[-1][-1]:
            result[-1] = (result[-1][0], max(result[-1][-1], end))
        else:
            result.append((start, end))
    return result

class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        intervals = [[start, start + duration] for start in timeSeries]
        intervals = mergeIntervals(intervals)
        print(intervals)
        total = 0
        for start, end in intervals:
            total += end - start

        return total
