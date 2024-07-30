class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        idx = n + m - 1

        n -= 1
        m -= 1
        while n >= 0 and m >= 0:
            if nums1[m] < nums2[n]:
                nums1[idx] = nums2[n]
                n -= 1
            else:
                nums1[idx] = nums1[m]
                nums1[m] = 0
                m -= 1
            idx -= 1
        
        while n >= 0:
            nums1[idx] = nums2[n]
            n -= 1
            idx -= 1

        while m >= 0:
            nums1[idx] = nums1[m]
            m -= 1
            idx -= 1
