def symmetryCheck(left: Optional[TreeNode], right: Optional[TreeNode]) -> bool:
    if left.val != right.val:
        return False

    outside, inside = False, False
    if left.left and right.right:
        outside = symmetryCheck(left.left, right.right)
    elif left.left == right.right:
        outside = True

    if left.right and right.left:
        inside = symmetryCheck(left.right, right.left)
    elif left.right == right.left:
        inside = True
    
    return outside and inside
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True

        return symmetryCheck(root, root)
