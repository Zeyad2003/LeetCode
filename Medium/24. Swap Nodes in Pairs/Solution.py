class Solution(object):
    def swapPairs(self, head):
        if head is None:
            return None
        ret = ListNode(0)
        ret.next = head
        first = head
        prev = ret

        while first and first.next:
            go = first.next.next
            second = first.next

            first.next = go
            second.next = first
            prev.next = second

            prev = first
            first = go

        return ret.next