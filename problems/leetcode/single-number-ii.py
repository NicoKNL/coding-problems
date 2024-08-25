class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        nums.sort()

        i = 0
        while i < len(nums) - 3:
            if nums[i] == nums[i + 1]:
                i += 3
            else:
                return nums[i]
        
        return nums[-1]
