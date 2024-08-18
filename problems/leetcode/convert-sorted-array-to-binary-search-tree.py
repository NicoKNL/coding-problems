def recurse(nums: List[int], L: int, R: int) -> Optional[TreeNode]:
    if L > R or L < 0 or R >= len(nums):
        return

    if L == R:
        return TreeNode(nums[L])

    n = (L + R) // 2
    root = TreeNode(nums[n])
    root.left = recurse(nums, L, n - 1)
    root.right = recurse(nums, n + 1, R)
    return root

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        n = len(nums)
        if n == 0:
            return

        return recurse(nums, 0, n - 1)
