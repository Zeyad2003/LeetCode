# [141. Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)

## Solution
- [Slow - Accepted]: Use map to record the visited node, if the node is visited, then there is a cycle.
- [Fast - Accepted]: Use two pointers, one pointer move one step each time, another pointer move two steps each time. If the two pointers meet, then there is a cycle.

## Complexity
- Time Complexity: 
    - Using map: `O(nlog(n))`, where `n` is the number of nodes in the linked list.
    - Using two pointers: `O(n)`, where `n` is the number of nodes in the linked list.
- Space complexity: 
    - Using map: `O(n)`, where `n` is the number of nodes in the linked list.
    - Using two pointers: `O(1)`.

## Code
- Using a map to store the visited nodes.
``` cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = (int) nums.size();
        int l = 0, r = n - 1;
        while(l < r) {
            int mid = l + (r - l) / 2;

            if(nums[mid] > nums[r]) // left is sorted so min is in right
                l = mid + 1;
            else // right is sorted so min is in left
                r = mid;
        }
        return nums[l];
    }
};
```

- Using two pointers to find the cycle.
``` cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false; // If there's no nodes, there's no cycles
        auto *fast = head;
        while(fast->next and fast->next->next) { // While there's 2 nodes forward
            fast = fast->next->next; // Move fast pointer 2 nodes forward
            head = head->next; // Move head pointer one node forward
            if(head == fast) // If they meet again there's a cycle
                return true;
        }
        return false; // No cycle found
    }
};
```