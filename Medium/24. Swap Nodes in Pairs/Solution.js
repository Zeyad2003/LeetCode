var swapPairs = function(head) {
    if(!head) return null;
    let ret = new ListNode(0);
    ret.next = head;
    let first = head;
    let prev = ret;

    while(first && first.next) {
        let go = first.next.next;
        let second = first.next;

        first.next = go;
        second.next = first;
        prev.next = second;

        prev = first;
        first = go;
    }

    return ret.next;
};