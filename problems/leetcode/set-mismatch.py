from collections import defaultdict

def findMissing(nums: List[int]) -> int:
    n = len(nums)

    ALL = set(range(1, n + 1))
    ACTUAL = set(nums)

    missing = ALL - ACTUAL
    return missing.pop()


def findDuplicate(nums: List[int]) -> int:
    COUNTER = defaultdict(int)

    for num in nums:
        COUNTER[num] += 1
        if COUNTER[num] > 1:
            return num

class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        return [findDuplicate(nums), findMissing(nums)]
