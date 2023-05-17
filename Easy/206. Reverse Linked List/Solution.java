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
}