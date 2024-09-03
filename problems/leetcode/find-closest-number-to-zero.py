class Solution:
    def findClosestNumber(self, nums: List[int]) -> int:
        nums.sort(reverse=True)
        nums.sort(key=lambda x: abs(x))
        return nums[0]
