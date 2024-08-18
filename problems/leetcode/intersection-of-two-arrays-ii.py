from collections import defaultdict

class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        M1 = defaultdict(int)
        M2 = defaultdict(int)

        for num in nums1:
            M1[num] += 1
        
        for num in nums2:
            M2[num] += 1

        result = []

        for num in set(nums1) | set(nums2):
            for _ in range(min(M1[num], M2[num])):
                result.append(num)

        return result
