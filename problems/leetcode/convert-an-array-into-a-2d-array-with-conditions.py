class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        result = []

        while sum(nums):
            S = set()
            for i, n in enumerate(nums):
                if n:
                    if n not in S:
                        nums[i] = 0
                        S.add(n)
            result.append(list(S))
        
        return result
