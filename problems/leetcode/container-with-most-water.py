class Solution:
    def maxArea(self, height: List[int]) -> int:
        lo = 0
        hi = len(height) - 1

        area = min(height[lo], height[hi]) * (hi - lo)
        while lo < hi:
            if height[lo] < height[hi]:
                lo += 1
            else:
                hi -= 1
            area = max(area, min(height[lo], height[hi]) * (hi - lo))
        
        return area
