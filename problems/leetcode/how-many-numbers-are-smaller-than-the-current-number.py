class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        order = sorted(nums)
        result = [0 for _ in range(len(nums))]

        for i, n in enumerate(nums):
            idx = order.index(n)
            if idx != -1:
                result[i] = idx
        
        return result
