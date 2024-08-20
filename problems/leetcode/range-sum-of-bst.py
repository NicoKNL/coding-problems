# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        total = 0

        Q = [root]
        i = 0

        while i < len(Q):
            current = Q[i]
            i += 1
            if not current:
                continue

            if low <= current.val <= high:
                total += current.val

            if current.left and low <= current.val:
                Q.append(current.left)

            if current.right and current.val <= high:
                Q.append(current.right)
        
        return total
