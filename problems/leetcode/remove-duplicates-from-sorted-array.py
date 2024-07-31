class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        SEEN = set()
        for i in range(len(nums)):
            if nums[i] in SEEN:
                nums[i] = "_"
            SEEN.add(nums[i])

        for i in range(len(nums)):
            if nums[i] != "_":
                ii = i - 1
                while ii >= 0 and nums[ii] == "_":
                    nums[i], nums[ii] = nums[ii], nums[i]
                    ii -= 1
                    i -= 1

        if "_" in nums:
            return nums.index("_")
        else:
            return len(nums)
