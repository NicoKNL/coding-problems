from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def getValues(c):
    values = []
    while c.next:
        values.append(c.val)
        c = c.next
    values.append(c.val)
    return values


class Solution:
    def mergeTwoLists(
        self, list1: Optional[ListNode], list2: Optional[ListNode]
    ) -> Optional[ListNode]:
        # TODO: Do actual merging instead of this.
        if not list1 and not list2:
            return

        if not list2:
            return list1

        if not list1:
            return list2

        values = getValues(list1)
        values.extend(getValues(list2))
        values.sort()

        root = ListNode(val=values[0])
        u = root
        for i in range(1, len(values)):
            u.next = ListNode(val=values[i])
            u = u.next

        return root


s = Solution()
a = ListNode(val=1, next=ListNode(2, next=ListNode(4)))
b = ListNode(val=1, next=ListNode(3, next=ListNode(4)))

c = s.mergeTwoLists(a, b)
