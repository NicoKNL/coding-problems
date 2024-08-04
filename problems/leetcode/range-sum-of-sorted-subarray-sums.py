class Solution:
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        subarrays = []

        for i in range(n):
            for ii in range(i, n):
                subarrays.append(sum(nums[i:ii + 1]))

        return sum(sorted(subarrays)[left - 1:right]) % (10**9 + 7)
