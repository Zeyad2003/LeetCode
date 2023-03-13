# [876. Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/)

## Solution
- Use `floyd cycle detection` algorithm to find the middle of the linked list
## Complexity
- Time Complexity: `O(n)` where `n` is the number of nodes in the linked list.

- Space Complexity: `O(1)`.
## Code
```cpp
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        auto *fast = head, *slow = head; // Set both pointers to the head
        while(fast and fast->next) { // While fast can move two steps forward
            slow = slow->next; // Move slow one step
            fast = fast->next->next; // Move fast two steps
        }
        return slow; // Slow will be the middle at this point, so return it.
    }
};
```