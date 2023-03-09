# [142. Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/)

## Solution
- Apply Floyd's Cycle Detection Algorithm to detect the cycle and find the start point of the cycle
## Complexity
- Time complexity: `O(n)`, where n is the size of the LinkedList.

- Space complexity: `O(1)`

## Code
``` cpp
// Zeyad Nasef
/*
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head or !head->next) return nullptr; // just one node -> no cycle

        auto *fast = head;
        auto *slow = head;

        while(fast->next and fast->next->next) {
            slow = slow->next; // 1x
            fast = fast->next->next; // 2x
            if(fast == slow) { // cycle detected
                fast = head; // reset fast to head
                while(fast != slow) { // keep moving until they meet again at the start of the cycle
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast; // return the start of the cycle
            }
        }

        return nullptr; // no cycle
    }
};
```