def reverseList(head):
    if not head or not head.next:
        return head
    cur = head.next
    head.next = None

    while cur is not None:
        go = cur.next
        cur.next = head
        head = cur
        cur = go

    return head
class Solution(object):
    def pairSum(self, head):
        fast = head
        slow = head
        while fast is not None:
            fast = fast.next.next
            slow = slow.next

        startReversed = reverseList(slow)
        ans = 0
        while startReversed is not None:
            ans = max(ans, head.val + startReversed.val)
            head = head.next
            startReversed = startReversed.next

        return ans