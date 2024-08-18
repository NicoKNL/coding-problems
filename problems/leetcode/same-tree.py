def treeAsList(t: Optional[TreeNode]) -> List[str]:
    Q = [t]
    Qi = 0
    result = []
    while Qi < len(Q):
        node = Q[Qi]
        if node:
            result.append(str(node.val))
            Q.append(node.left)
            Q.append(node.right)
        else:
            result.append("null")
        Qi += 1
    return result

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        return treeAsList(p) == treeAsList(q)
