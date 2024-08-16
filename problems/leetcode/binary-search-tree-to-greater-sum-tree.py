TOTAL = 0

def augment(root: TreeNode):
    global TOTAL
    if not root:
        return
    
    augment(root.right)
    root.val += TOTAL
    TOTAL = root.val
    augment(root.left)


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        global TOTAL
        TOTAL = 0
        
        augment(root)
        return root
