# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        values = []

        Q = [root1, root2]
        i = 0

        while i < len(Q):
            current = Q[i]
            i += 1

            if not current:
                continue

            values.append(current.val)
            Q.append(current.left)
            Q.append(current.right)
        
        return list(sorted(values))
