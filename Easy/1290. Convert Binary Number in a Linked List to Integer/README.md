# [1290. Convert Binary Number in a Linked List to Integer](https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/)

## Solution
- Loop through the linked list and push the value of each node to the back of the string.
- Convert the string to an integer using `stoi(str, 0, 2)`.
## Complexity
- Time Complexity: `O(n)` where `n` is the number of nodes.

- Space Complexity: `O(n)` for the string size.
## Code
```cpp
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        string str; // ddd linked list values to the string
        while(head) {
            str.push_back(head->val + '0'); // convert the number to char and push it back to the string
            head = head->next; // move to the next node
        }
        return stoi(str, 0, 2); // convert the string to decimal
    }
};
```