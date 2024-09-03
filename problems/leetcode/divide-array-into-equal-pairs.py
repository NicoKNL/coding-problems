from collections import defaultdict

class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        COUNTER = defaultdict(int)
        for num in nums:
            COUNTER[num] += 1

        return all([v % 2 == 0 for v in COUNTER.values()])
