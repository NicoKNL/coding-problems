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
