from collections import defaultdict

class Solution:
    def isPossibleToSplit(self, nums: List[int]) -> bool:
        COUNTER = defaultdict(int)
        for num in nums:
            COUNTER[num] += 1
            if COUNTER[num] > 2:
                return False

        return True
