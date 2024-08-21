class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = len(nums) - 3
        while i >= 0:
            if nums[i] == nums[i + 1] and nums[i + 1] == nums[i + 2]:
                del nums[i]
            i -= 1
        return len(nums)
