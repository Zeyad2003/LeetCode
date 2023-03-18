# [124. Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/)

## Solution
- Apply `DFS` to traverse the in post-order, and record the compare between 4 things:
<ol>
    <li> Taking just the root node.</li>
    <li> Taking the root node + the left subtree.</li>
    <li> Taking the root node + the right subtree.</li>
    <li> Taking the root node + left subtree + right subtree.</li>
</ol>

## Complexity
- **Time Complexity**: `O(n)`, where `n` is the number of nodes in the tree.
- **Space Complexity**: `O(log(n))`, for the recursive stack.

## Code
```cpp
class Solution {
private:
    const static int oo = 1e9;
public:
    int dfs(TreeNode *root, int&res) {
        if(root == nullptr)
            return 0;

        int right = dfs(root->right, res);
        int left = dfs(root->left, res);

        int justRoot = root->val;

        // Choose the max sum from the 2 children take the best choice to take just the root or the root + one of the children
        int choose = max(justRoot, max(left, right) + justRoot);

        // May the answer is the current subtree so maximize between it and our previous choice
        res = max({res, choose, left + right + justRoot});
        return choose;
    }

    int maxPathSum(TreeNode* root) {
        int res = -oo;
        dfs(root, res);
        return res;
    }
};
```