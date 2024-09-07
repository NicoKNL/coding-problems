from functools import cache

def augmentWithParent(root: Optional[TreeNode], parent: TreeNode) -> None:
    if not root:
        return

    root.parent = parent
    if root.left:
        augmentWithParent(root.left, root)
    
    if root.right:
        augmentWithParent(root.right, root)

def getLastNodeInList(head: Optional[ListNode]) -> Optional[ListNode]:
    if not head:
        return None
    
    while head.next:
        head = head.next
    
    return head

def getListLength(head: Optional[ListNode]) -> int:
    length = 0

    while head.next:
        head = head.next
        length += 1
    
    return length

def getNodesWithMinimumDepth(root: Optional[TreeNode], target: int, depth: int) -> List[TreeNode]:
    result = []

    Q = [(root, 0)]
    i = 0

    while i < len(Q):
        node, d = Q[i]
        i += 1

        if not node:
            continue

        if node.val == target and d >= depth:
            result.append(node)
        
        if node.left:
            Q.append((node.left, d + 1))

        if node.right:
            Q.append((node.right, d + 1))
    
    return result

@cache
def reverseAsList(head: ListNode) -> List[int]:
    result = []

    while head:
        result.append(head.val)
        head = head.next
    
    return result[::-1]

def reverseMatch(start: TreeNode, head: ListNode) -> bool:
    reversed_list = reverseAsList(head)
    i = 0

    while i < len(reversed_list) and reversed_list[i] == start.val:
        i += 1
        start = start.parent
    
    return i == len(reversed_list)
    

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubPath(self, head: Optional[ListNode], root: Optional[TreeNode]) -> bool:
        augmentWithParent(root, None)
        target = getLastNodeInList(head)
        depth = getListLength(head)

        if not target:
            return True

        starts = getNodesWithMinimumDepth(root, target.val, depth)
        for start in starts:
            if reverseMatch(start, head):
                return True

        return False
