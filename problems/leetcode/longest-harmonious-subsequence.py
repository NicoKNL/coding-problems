from collections import defaultdict
from itertools import pairwise

class Solution:
    def findLHS(self, nums: List[int]) -> int:
        COUNT = defaultdict(int)

        for num in nums:
            COUNT[num] += 1
        
        candidates = list(COUNT.keys())
        candidates.sort()

        result = 0
        for a, b in pairwise(candidates):
            if b - a == 1:
                result = max(result, COUNT[a] + COUNT[b])
        
        return result
