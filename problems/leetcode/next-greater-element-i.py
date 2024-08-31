class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        result = []
        for num in nums1:
            i = nums2.index(num)
            v = -1
            for ii in range(i + 1, len(nums2)):
                if nums2[ii] > num:
                    v = nums2[ii]
                    break
            result.append(v)

        return result
