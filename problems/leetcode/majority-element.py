class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count = 1
        majority = nums[0]

        for i in range(1, len(nums)):
            if nums[i] == majority:
                count += 1
            else:
                count -= 1
                if count < 0:
                    majority = nums[i]
                    count = 0
        
        return majority
