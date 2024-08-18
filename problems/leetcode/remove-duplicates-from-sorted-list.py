# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        root = head
        SEEN = set()

        while True:
            if not head:
                break

            SEEN.add(head.val)

            if head.next:
                if head.next.val not in SEEN:
                    SEEN.add(head.val)
                else:
                    head.next = head.next.next
                    continue

            head = head.next

        return root
