"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

def recurse(root: 'Node', result: List[int]):
    if not root:
        return
        
    for child in root.children:
        recurse(child, result)
    
    result.append(root.val)

class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        result = []

        recurse(root, result)

        return result
