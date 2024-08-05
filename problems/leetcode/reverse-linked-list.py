# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return

        values = []

        while True:
            if not head:
                break
            
            values.append(head.val)
            head = head.next
        
        rev_head = ListNode(values[-1])
        rev_root = rev_head
        i = len(values) - 2
        while i >= 0:
            rev_head.next = ListNode(values[i])
            i -= 1
            rev_head = rev_head.next
        
        return rev_root
