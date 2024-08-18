class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)

        result = set()
        for a in range(len(nums) - 2):
            if a > 0 and nums[a] == nums[a - 1]:
                continue

            b = a + 1
            c = len(nums) - 1

            while b < c:
                total = nums[a] + nums[b] + nums[c]
                if total == 0:
                    result.add((nums[a], nums[b], nums[c]))
                    b += 1
                    c -= 1
                elif total < 0:
                    b += 1
                else:
                    c -= 1
        
        return list(result)
