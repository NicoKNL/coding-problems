class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        best = max(candies)
        result = []
        for kid in candies:
            if kid + extraCandies >= best:
                result.append(True)
            else:
                result.append(False)
        return result
