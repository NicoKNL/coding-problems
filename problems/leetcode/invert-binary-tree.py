# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        Q = [root]
        i = 0
        while i < len(Q):
            u = Q[i]
            i += 1
            if not u:
                continue
            
            u.left, u.right = u.right, u.left

            Q.append(u.left)
            Q.append(u.right)
        
        return root
