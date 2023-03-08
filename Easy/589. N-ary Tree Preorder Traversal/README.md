# [589. N-ary Tree Preorder Traversal](https://leetcode.com/problems/n-ary-tree-preorder-traversal/)

## Solution
- DFS Algorithm visit the nodes in preorder (root -> left -> right).
- You can apply the algorithm and store the values of every node in a vector.
## Complexity
- Time complexity: `O(n)`, where n is the number of nodes in the tree

- Space complexity: `O(1)`.

## Code

```cpp
class Solution {
public:

    void dfs(Node*root, vector<int> &ans) {
        if(!root) return;
        ans.emplace_back(root->val); // Put the current node in the answer

        for(auto &child : root->children) // Traverse all the children in preorder manner
            dfs(child, ans);
    }

    vector<int> preorder(Node* root) {
        vector<int> ans; // To store the answer
        if(!root) return ans; // If the root is null, return the empty vector
        dfs(root, ans); // Apply DFS
        return ans;
    }
};
```