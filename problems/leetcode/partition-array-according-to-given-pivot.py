class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        smaller = []
        pivots = []
        larger = []
        for num in nums:
            if num < pivot:
                smaller.append(num)
            elif num == pivot:
                pivots.append(num)
            else:
                larger.append(num)
        
        return smaller + pivots + larger
