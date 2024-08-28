class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        S = set(nums)

        result = 0
        for num in nums:
            if num - 1 not in S:
                length = 1
                while num + 1 in S:
                    length += 1
                    num += 1
                
                result = max(result, length)
            
        return result
