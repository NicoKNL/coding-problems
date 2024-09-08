from math import ceil

def getTargetLengths(n: int, k: int) -> List[int]:
    result = [0 for _ in range(k)]
    for i in range(n):
        result[i % k] += 1
    return result


def countNodes(head: Optional[ListNode]) -> int:
    count = 0
    while head:
        count += 1
        head = head.next
    return count

def getHeadsAtSpacing(head: Optional[ListNode], intervals: List[int]) -> List[ListNode]:
    heads = [head]
    
    for interval in intervals:
        for i in range(interval):
            if not head.next:
                return heads
            head = head.next
        heads.append(head)
    return heads

def detach(head: ListNode, depths: List[int]) -> None:
    for depth in depths:
        while depth > 1 and head.next:
            depth -= 1
            head = head.next
        
        if not head.next:
            continue
        tmp = head.next
        head.next = None
        head = tmp
        
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        if not head:
            return [None for _ in range(k)]
            
        n = countNodes(head)
        targets = getTargetLengths(n, k)
        print(targets)
        parts = getHeadsAtSpacing(head, targets)

        for part in parts:
            detach(part, targets)

        while len(parts) < k:
            parts.append(None)
        
        return parts
