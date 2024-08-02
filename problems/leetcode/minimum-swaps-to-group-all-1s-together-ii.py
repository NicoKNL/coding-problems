class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        if 1 not in nums:
            return 0

        ones = nums.count(1)
        nums.extend(nums)
        zeroes = 0
        for i in range(ones):
            if nums[i] == 0:
                zeroes += 1

        min_zeroes = zeroes
        for i in range(1, len(nums) - ones):
            if nums[i - 1] == 0:
                zeroes -= 1
            if nums[i + ones - 1] == 0:
                zeroes += 1
            min_zeroes = min(zeroes, min_zeroes)
        
        return min_zeroes
