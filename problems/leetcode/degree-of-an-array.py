class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        M = dict()

        degree = 0
        for i, num in enumerate(nums):
            if num not in M:
                M[num] = [i, i, 1]
            else:
                l, r, count = M[num]
                M[num] = [l, i, count + 1]
            
            degree = max(degree, M[num][2])
        
        best = 99999999999
        for l, r, count in M.values():
            if count == degree:
                best = min(best, r - l + 1)
        
        return best
