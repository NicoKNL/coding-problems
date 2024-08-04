class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if not nums:
            return nums
            
        splits = []
        for i in range(len(nums) - 1):
            if nums[i + 1] - nums[i] > 1:
                splits.append(i)
        splits.append(len(nums) - 1)

        result = []

        a = 0
        for b in splits:
            if a == b:
                result.append(f"{nums[a]}")
            else:
                result.append(f"{nums[a]}->{nums[b]}")
            a = b + 1

        return result
