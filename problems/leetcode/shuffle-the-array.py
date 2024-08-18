class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        result = []
        times = len(nums) // n

        for i in range(n):
            for ii in range(times):
                result.append(nums[ii * n + i])

        return result
