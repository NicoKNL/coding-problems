from collections import defaultdict

class Solution:
    def mostFrequent(self, nums: List[int], key: int) -> int:
        COUNT = defaultdict(int)

        best = 0
        num = 0
        for i in range(len(nums) - 1):
            if nums[i] == key:
                COUNT[nums[i + 1]] += 1
                if COUNT[nums[i + 1]] > best:
                    best = COUNT[nums[i + 1]]
                    num = nums[i + 1]
        
        return num
