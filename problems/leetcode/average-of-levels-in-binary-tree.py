from collections import defaultdict

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        VALUES = defaultdict(list)

        Q = [(root, 0)]
        i = 0

        while i < len(Q):
            node, depth = Q[i]
            i += 1

            if not node:
                continue

            VALUES[depth].append(node.val)
            if node.left:
                Q.append((node.left, depth + 1))
            if node.right:
                Q.append((node.right, depth + 1))

        result = []
        for k in sorted(VALUES.keys()):
            result.append(sum(VALUES[k]) / len(VALUES[k]))
        return result
