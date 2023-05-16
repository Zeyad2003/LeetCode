# [24. Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/)

## Solution:
- You just need to change the direction of `next` pointers.
- First for every pair of nodes, you should have a previous node that points to the first node of the pair.
- Then you should change the next of the second node and make it points to the first node.
- Also, you should make the next of the previous node points to the second node.
- Finally, the next of the first node should point to the next pair of nodes, which we will be stored previously.

## Complexity
- Time Complexity: `O(N)`, where `N` is the number of nodes in the linked list.

- Space Complexity: `O(1)`

## Code
### C++
```cpp
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head) return nullptr;
        auto * ret = new ListNode(0);
        ret->next = head;
        auto *first = head;
        auto *prev = ret;

        while(first and first->next) {
            auto *go = first->next->next;
            auto *second = first->next;

            first->next = go;
            second->next = first;
            prev->next = second;

            prev = first;
            first = go;
        }

        return ret->next;
    }
};
```

### JavaScript
```javascript
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
```

### Python
```python
class Solution(object):
  def swapPairs(self, head):
    if head is None:
      return None
    ret = ListNode(0)
    ret.next = head
    first = head
    prev = ret

    while first and first.next:
      go = first.next.next
      second = first.next

      first.next = go
      second.next = first
      prev.next = second

      prev = first
      first = go

    return ret.next
```

### Java
```java
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
```