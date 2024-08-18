def recurse(root: Optional[TreeNode], depth: int) -> int:
    if not root.left and not root.right:
        return depth

    left = 99999
    if root.left:
        left = recurse(root.left, depth + 1)
    
    right = 99999
    if root.right:
        right = recurse(root.right, depth + 1)

    return min(left, right)


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        return recurse(root, 1)
