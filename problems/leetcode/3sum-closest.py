class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums = sorted(nums)

        optimal = 9999999
        ans = 0
        for a in range(len(nums) - 2):
            if optimal == 0:
                break

            b = a + 1
            c = len(nums) - 1

            while b < c:
                total = nums[a] + nums[b] + nums[c]
                if total == target:
                    optimal = 0
                    ans = target
                    break
                else:
                    if abs(target - total) < optimal:
                        optimal = abs(target - total)
                        ans = total

                    if total < target:
                        b += 1
                    else:
                        c -= 1
        
        return ans
