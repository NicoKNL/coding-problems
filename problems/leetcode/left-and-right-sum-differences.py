class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        left = list(accumulate([0] + nums))[:-1]
        right = list(accumulate([0] + nums[::-1]))[:-1][::-1]

        result = []
        for l, r in zip(left, right):
            result.append(abs(l - r))
        
        return result
