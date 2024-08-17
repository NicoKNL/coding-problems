class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        total = 0
        for num in nums:
            total ^= num
        
        mismatch = total ^ k
        return bin(mismatch).count("1")
