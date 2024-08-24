class Solution:
    def canJump(self, nums: List[int]) -> bool:
        reachable = [False for _ in range(len(nums))]
        reachable[0] = True
        for i in range(len(reachable)):
            if reachable[i]:
                for ii in range(i, min(i + nums[i] + 1, len(reachable))):
                    reachable[ii] = True

        return reachable[-1]
