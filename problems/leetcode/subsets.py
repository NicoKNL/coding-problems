from itertools import combinations

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        superset = []
        for i in range(len(nums) + 1):
            superset.extend(list(combinations(nums, i)))
        
        return superset
