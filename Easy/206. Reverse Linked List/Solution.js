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