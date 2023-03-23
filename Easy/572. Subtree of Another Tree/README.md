# [572. Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree/)

## Solution
- Apply `DFS` on both `root` and `subRoot` and build a string for traversing them and add `','` to mark every node position.
- Finally, compare if the full string contain the sub one.
## Complexity
- **Time Complexity**: `O(n)`, where `n` is the number of nodes in the tree.
- **Space Complexity**: `O(n)`, for the string size of the tree.

## Code
```cpp
class Solution {
public:

    string flatten(TreeNode *root) { // Flatten the tree and add ',' to mark every position of the nodes 
        if(!root) return ",";
        return "," + to_string(root->val) + "," + flatten(root->left) + "," + flatten(root->right) + ",";
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string str = flatten(root); // Flatten the tree
        string sub = flatten(subRoot); // Flatten the subtree
        return str.find(sub) != string::npos; // Check if sub is exist inside the str -> root
    }
};
```