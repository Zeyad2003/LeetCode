class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head == null) return null;
        ListNode ret = new ListNode(0);
        ret.next = head;
        ListNode first = head;
        ListNode prev = ret;

        while(first != null && first.next != null) {
            ListNode go = first.next.next;
            ListNode second = first.next;

            first.next = go;
            second.next = first;
            prev.next = second;

            prev = first;
            first = go;
        }

        return ret.next;
    }
}