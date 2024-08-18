from collections import defaultdict
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        COUNTER = defaultdict(int)

        for num in nums:
            COUNTER[num] += 1

        for num, count in COUNTER.items():
            if count == 1:
                return num
