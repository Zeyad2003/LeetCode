# [206. Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)

## Solution:
- Before beginning to reverse, make sure that there's more than one node in the linked list.
- First you need to set the next pointer of the first node with null as it will be the last node in the reversed linked list.
- Then start from second node and track three node consecutive nodes, `head`, `curr` and `go`.
- The `head` will be the previous node of the `cur` node, and `go` will be the next node of the `cur` node.
- Then you just need to change the direction of the next pointers and move forward.
- `cur->next = head` will reverse the pointer direction of the `cur` node.
- `head = cur` will move the `head` pointer to the `cur` node, and it's equal to `head = head->next` in the normal list.
- `cur = go` will move the `cur` pointer to the `go` node, and it's equal to `cur = cur->next` in the normal list.
- Finally, `head` pointer will be pointing to the first node of the reversed linked list, so return it.

## Complexity
- Time Complexity: `O(N)`, where `N` is the number of nodes in the linked list.

- Space Complexity: `O(1)`

## Code
### C++
```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head or !head->next) return head;
        auto *cur = head->next;
        head->next = nullptr;
        while(cur) {
            auto *go = cur->next;
            cur->next = head;
            head = cur;
            cur = go;
        }
        return head;
    }
};
```

### JavaScript
```javascript
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
```

### Python
```python
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
```

### Java
```java
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
```