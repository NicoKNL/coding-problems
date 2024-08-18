from functools import reduce

class Solution:
    def xorOperation(self, n: int, start: int) -> int:
        nums = []
        while len(nums) < n:
            if not nums:
                nums.append(start)
            else:
                nums.append(nums[-1] + 2)
        
        return reduce(lambda x, y: x ^ y, nums)
