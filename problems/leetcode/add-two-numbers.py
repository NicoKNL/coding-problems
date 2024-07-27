def listAsNumber(l: Optional[ListNode]) -> int:
    n = 0
    d = 1

    while l:
        n += l.val * d
        d *= 10
        l = l.next

    return n


def numberAsList(n: int) -> Optional[ListNode]:
    root = ListNode(n % 10)
    n //= 10

    node = root
    while n:
        next_node = ListNode(n % 10)
        n //= 10
        node.next = next_node
        node = next_node

    return root


class Solution:
    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        a = listAsNumber(l1)
        b = listAsNumber(l2)

        return numberAsList(a + b)
