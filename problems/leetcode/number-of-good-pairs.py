class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        count = 0
        for i in range(len(nums) - 1):
            for ii in range(i + 1, len(nums)):
                if nums[i] == nums[ii]:
                    count += 1

        return count
