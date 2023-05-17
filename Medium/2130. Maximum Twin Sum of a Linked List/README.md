# [2130. Maximum Twin Sum of a Linked List](https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/)

## Solution:
- Review these two problems before we start [206. Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/) and [876. Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/) because we gonna use the same trick here.
- First you need to find the middle node of the linked list, then reverse the second half of the linked list.
- Now the first node in the first half is twin with the first node in the second half.
- You just need to iterator over the two half of the linked list and pick the maximum sum of the twin nodes.

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

    int pairSum(ListNode* head) {
        auto *fast = head, *slow = head;
        while(fast) {
            fast = fast->next->next;
            slow = slow->next;
        }

        auto *startReversed = reverseList(slow);
        int ans = 0;
        while(startReversed) {
            ans = max(ans, head->val + startReversed->val);
            head = head->next;
            startReversed = startReversed->next;
        }
        return ans;
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
```

### Python
```python
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
```