def swap(a: ListNode, b: ListNode) -> ListNode:
    a.next = b.next
    b.next = a
    return b

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        current = head

        while current and current.next:
            if prev:
                prev.next = swap(current, current.next)
            else:
                head = swap(current, current.next)
            prev = current
            current = current.next
        
        return head
