# [235. Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)

## Solution
- You can check some conditions to decide if you found the `LCA` or you should go to right or left based on the conditions in the code.
## Complexity
- Time Complexity: `O(n)` where `n` is the number of nodes in the tree.
- Space Complexity: `O(h)`, where `h` is the height of the tree.
## Code
```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val == p->val) return p; // Found it first so it's the LCA
        if(root->val == q->val) return q; // Same as above condition
        if((root->val < p->val and root->val > q->val) or (root->val > p->val and root->val < q->val)) return root; // Current root is the LCA
        if(root->val < p->val and root->val < q->val) return lowestCommonAncestor(root->right, p, q); // Move right
        return lowestCommonAncestor(root->left, p, q); // Move left
    }
};
```