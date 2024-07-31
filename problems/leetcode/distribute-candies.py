class Solution:
    def distributeCandies(self, candyType: List[int]) -> int:
        unique_types = len(set(candyType))
        return min(unique_types, len(candyType) // 2)
