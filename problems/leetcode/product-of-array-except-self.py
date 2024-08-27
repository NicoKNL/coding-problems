from functools import reduce

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        if nums.count(0) == 1:
            result = [0 for _ in range(len(nums))]
            idx = nums.index(0)
            nums[idx] = 1
            result[idx] = reduce(lambda x, y: x * y, nums)
            return result

        if nums.count(0) >= 2:
            return [0 for _ in range(len(nums))]
        
        total = reduce(lambda x, y: x * y, nums)

        result = []
        for num in nums:
            result.append(total // num)
        
        return result
