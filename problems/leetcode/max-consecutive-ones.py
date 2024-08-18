class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        s = "".join(map(str, nums))
        return max(len(x) for x in s.split("0"))
