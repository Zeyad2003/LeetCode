# [230. Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)

## Solution
- Use `in-order` traversal to get the values in the tree sorted and store them in a vector, and when you reach the kth element, return the back of the vector
## Complexity
- Time Complexity: `O(k)` to fill the array with the first `k` smallest elements.
- Space Complexity: `O(k)`, to store the previous sorted elements.
## Code
```cpp
class Solution {
public:

    int build(TreeNode*root, vector<int>& sorted, int k) {
        if(root->left) build(root->left, sorted, k);
        if(sorted.size() == k) return sorted.back();
        sorted.emplace_back(root->val);
        if(root->right) build(root->right, sorted, k);
        return sorted.back();
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> sorted;
        return build(root, sorted, k);
    }
};
```