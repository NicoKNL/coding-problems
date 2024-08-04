# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        count = 0

        Q = [root]
        i = 0

        while i < len(Q):
            root = Q[i]
            i += 1

            if root:
                count += 1
            else:
                continue
            
            if root.left:
                Q.append(root.left)
            
            if root.right:
                Q.append(root.right)
        
        return count
