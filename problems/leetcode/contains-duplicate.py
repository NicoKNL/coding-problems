class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        SEEN = set()
        for num in nums:
            if num in SEEN:
                return True
            SEEN.add(num)
        return False
