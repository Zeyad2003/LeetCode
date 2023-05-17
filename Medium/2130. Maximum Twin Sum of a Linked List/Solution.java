class Solution {
    public ListNode reverseList(ListNode head) {
        if(head == null || head.next == null) return head;
        ListNode cur = head.next;
        head.next = null;
        while(cur != null) {
            ListNode go = cur.next;
            cur.next = head;
            head = cur;
            cur = go;
        }
        return head;
    }

    public int pairSum(ListNode head) {
        ListNode fast = head, slow = head;
        while(fast != null) {
            fast = fast.next.next;
            slow = slow.next;
        }

        ListNode startReversed = reverseList(slow);
        int ans = 0;
        while(startReversed != null) {
            ans = Math.max(ans, head.val + startReversed.val);
            head = head.next;
            startReversed = startReversed.next;
        }
        return ans;
    }
}