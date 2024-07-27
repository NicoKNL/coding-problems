class Solution:
    def removeElement(self, nums: List[int], val: int):
        if val not in nums:
            return len(nums)

        l, r = 0, len(nums) - 1
        count = 0
        while l < r:
            if nums[r] == val:
                r -= 1
            elif nums[l] == val:
                nums[l], nums[r] = nums[r], nums[l]
                l += 1
                count += 1
            else:
                l += 1
        
        return nums.index(val)
