class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = nums.count(0)
        next_nums = [x for x in nums if x != 0]
        next_nums.extend([0 for _ in range(n)])
        nums[:] = next_nums[:]
