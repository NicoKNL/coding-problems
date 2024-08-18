from itertools import accumulate

class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        total = sum(nums)
        
        prefix_sum = [0] + list(accumulate(nums)) + [0]
        suffix_sum = [0] + list(accumulate(nums[::-1]))[::-1] + [0]

        for i in range(1, len(prefix_sum) - 1):
            if prefix_sum[i - 1] == suffix_sum[i + 1]:
                return i - 1
        
        return -1
