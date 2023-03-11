# [109. Convert Sorted List to Binary Search Tree](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/)

## Solution
- [Not Efficient - Accepted]: Store the values in a vector and then build the tree from the vector.
- [Efficient - Accepted]: Apply in-order traversal and use `head` pointer to build the tree without using extra space.
## Complexity
- Time Complexity: `O(n)`, where `n` is the number of nodes in the linked list.

- Space Complexity:
    - Using vector: `O(n + log(n))`, for the recursion stack and the vector `store`.
    - Without using vector: `O(log(n))`, for the recursion stack.
## Code
- Using vector:
```cpp
class Solution {
public:
    vector<int> store; // Store linked list values

    TreeNode *buildTree(int start, int end) {
        if(start > end) return nullptr;

        int mid = (start + end) / 2; // Get the middle element
        auto *root = new TreeNode(store[mid]); // Make the middle element the root
        auto *left = buildTree(start, mid - 1); // Recursively build the left subtree with the same logic
        auto *right = buildTree(mid + 1, end); // Recursively build the right subtree with the same logic
        root->left = left; root->right = right; // Connect the left and right subtrees to the root
        return root; // Return the root node
    }

    TreeNode* sortedListToBST(ListNode* head) {
        while(head) { // Add values to the store vector
            store.emplace_back(head->val);
            head = head->next;
        }

        return buildTree(0, (int) store.size() - 1); // Return the root node of the BST
    }
};
```
- Without using vector:
```cpp
class Solution {
public:

    TreeNode *buildTree(ListNode*start, ListNode*end) {
        auto *slow = start, *fast = start; // Find the middle element
        if(start == end) return nullptr;

        while(fast != end and fast->next != end) { // Go to the middle point
            slow = slow->next;
            fast = fast->next->next;
        }

        auto *root = new TreeNode(slow->val); // Create the root with the middle value
        root->left = buildTree(start, slow); // Build the left subtree
        root->right = buildTree(slow->next, end); // Build the right subtree
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        return buildTree(head, nullptr); // Return the root node of the BST
    }
};
```