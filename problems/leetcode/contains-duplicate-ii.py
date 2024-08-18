from collections import defaultdict

class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        M = defaultdict(list)

        for i, num in enumerate(nums):
            M[num].append(i)

        for group in M.values():
            for i in range(len(group) - 1):
                if group[i + 1] - group[i] <= k:
                    return True
        
        return False
