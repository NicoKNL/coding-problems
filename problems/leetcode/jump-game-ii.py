class Solution:
    def jump(self, nums: List[int]) -> int:
        DP_DIST = [0 for _ in range(len(nums))]
        DP_DIST[0] = 1

        for i in range(len(DP_DIST)):
            if DP_DIST == 0:
                continue
            
            jump = nums[i]
            for ii in range(i, min(i + jump + 1, len(DP_DIST))):
                if DP_DIST[ii] == 0:
                    DP_DIST[ii] = DP_DIST[i] + 1
                else:
                    DP_DIST[ii] = min(DP_DIST[ii], DP_DIST[i] + 1)

        return DP_DIST[-1] - 1
