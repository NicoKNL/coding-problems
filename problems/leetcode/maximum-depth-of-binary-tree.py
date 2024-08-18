def recurse(root: Optional[TreeNode], depth: int) -> int:
    if not root:
        return depth
    
    left = 0
    if root.left:
        left = recurse(root.left, depth + 1)
    
    right = 0
    if root.right:
        right = recurse(root.right, depth + 1)

    return max(depth, max(left, right))

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        return recurse(root, 1)
