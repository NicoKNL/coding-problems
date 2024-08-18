# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        tmp = head
        pre_last = None

        while tmp.next:
            if tmp.next.val == 0:
                pre_last = tmp
                tmp = tmp.next
                continue

            tmp.val += tmp.next.val
            tmp.next = tmp.next.next
        
        if tmp.val == 0:
            pre_last.next = None

        return head
