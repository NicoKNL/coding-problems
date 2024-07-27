class Solution:
    def countPairs(self, nums: list[int], target: int) -> int:
        count = 0
        for i in range(len(nums)):
            for ii in range(i + 1, len(nums)):
                if nums[i] + nums[ii] < target:
                    count += 1
        return count
