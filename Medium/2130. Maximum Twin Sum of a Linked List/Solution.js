var reverseList = function (head) {
    if (head == null || head.next == null) return head;
    let cur = head.next;
    head.next = null;
    while (cur != null) {
        let go = cur.next;
        cur.next = head;
        head = cur;
        cur = go;
    }
    return head;
};

var pairSum = function(head) {
    let fast = head, slow = head;
    while (fast) {
        fast = fast.next.next;
        slow = slow.next;
    }

    let startReversed = reverseList(slow);
    let ans = 0;
    while (startReversed) {
        ans = Math.max(ans, head.val + startReversed.val);
        head = head.next;
        startReversed = startReversed.next;
    }
    return ans;
};