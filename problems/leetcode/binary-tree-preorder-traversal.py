from collections import defaultdict
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        visited = defaultdict(bool)
        stack = []
        stack.append(root)

        order = []
        while stack:
            root = stack[-1]
            stack.pop()

            if not root:
                continue

            if visited[root]:
                order.append(root.val)
                continue
            else:
                visited[root] = True

            if root.right:
                stack.append(root.right)

            if root.left:
                stack.append(root.left)
                
            stack.append(root)

        return order
