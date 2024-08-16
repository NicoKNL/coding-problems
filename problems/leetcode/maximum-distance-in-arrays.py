class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:
        candidates = []
        for i, nums in enumerate(arrays):
            candidates.append((nums[0], i))
            
            if len(nums) > 1:
                candidates.append((nums[-1], i))
        
        candidates = sorted(candidates)
        if candidates[0][1] != candidates[-1][1]:
            return abs(candidates[0][0] - candidates[-1][0])
        
        # candidates are from same array
        return max(
            abs(candidates[0][0] - candidates[-2][0]),
            abs(candidates[1][0] - candidates[-1][0])
        )
