class Solution(object):
    def reverseList(self, head):
        if not head or not head.next: return head
        cur = head.next
        head.next = None

        while cur:
            go = cur.next
            cur.next = head
            head = cur
            cur = go

        return head