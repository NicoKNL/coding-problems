from collections import defaultdict
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        LEAVES = defaultdict(int)

        Q = [(root, 0)]
        i = 0
        max_depth = -1

        while i < len(Q):
            current, depth = Q[i]
            i += 1

            if not current.left and not current.right:
                LEAVES[depth] += current.val
                max_depth = max(max_depth, depth)
            
            if current.left:
                Q.append((current.left, depth + 1))
            
            if current.right:
                Q.append((current.right, depth + 1))
        
        return LEAVES[max_depth]
