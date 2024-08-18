from itertools import combinations
from functools import reduce

class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        result = 0

        for length in range(len(nums) + 1):
            for each in combinations(nums, length):
                if each:
                    result += reduce(lambda x, y: x ^ y, each)
        
        return result
