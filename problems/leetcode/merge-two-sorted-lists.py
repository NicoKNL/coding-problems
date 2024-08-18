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
