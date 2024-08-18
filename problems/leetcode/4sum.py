class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums = sorted(nums)
        result = set()

        for a in range(len(nums) - 3):
            for b in range(a + 1, len(nums) - 2):
                total = nums[a] + nums[b]
                c = b + 1
                d = len(nums) - 1
                while c < d:
                    final = total + nums[c] + nums[d]
                    if final == target:
                        result.add((nums[a], nums[b], nums[c], nums[d]))
                        c += 1
                        d -= 1
                    elif final < target:
                        c += 1
                    else:
                        d -= 1

        return list(result)
