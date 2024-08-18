from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        count = 0

        end = head
        while end:
            end = end.next
            count += 1

        middle = count // 2

        target = head
        for _ in range(middle):
            target = target.next

        return target
