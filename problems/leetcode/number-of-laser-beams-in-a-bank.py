from functools import reduce

def contract(nums: List[int]) -> List[int]:
    return list(x * y for x, y in zip(nums, nums[1:]))

class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        rows = []
        for row in bank:
            total = row.count("1")
            if total:
                rows.append(total)

        return sum(contract(rows))
