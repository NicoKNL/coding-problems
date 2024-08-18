class Solution:
    def buildArray(self, nums: List[int]) -> List[int]:
        result = [x for x in nums]
        for idx in nums:
            result[idx] = nums[nums[idx]]
        return result
