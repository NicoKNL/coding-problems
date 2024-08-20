def recurse(root: Optional[TreeNode], target: int):
    if root.left:
        root.left = recurse(root.left, target)
    
    if root.right:
        root.right = recurse(root.right, target)

    if not root.left and not root.right:
        if root.val == target:
            return None
    
    return root
    
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def removeLeafNodes(self, root: Optional[TreeNode], target: int) -> Optional[TreeNode]:
        fake_root = TreeNode()
        fake_root.left = root
        recurse(fake_root, target)
        return fake_root.left
