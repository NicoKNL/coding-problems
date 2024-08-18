# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        SEEN = set()
        for _ in range(10**4 + 1):
            if not head:
                return False

            if head in SEEN:
                return True
            SEEN.add(head)
            head = head.next

        return False
