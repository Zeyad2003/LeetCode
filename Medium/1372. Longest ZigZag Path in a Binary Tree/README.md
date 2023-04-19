# [1372. Longest ZigZag Path in a Binary Tree](https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/)
![image](https://assets.leetcode.com/users/images/95e8eb11-89a5-4809-b9f4-8738ad7affc8_1681907979.890191.png)

## Solution
- Use `DFS` to traverse the tree and keep track with the length you have and the direction you come from.
- Keep a global variable `ans` to store the max length.
## Complexity
- Time Complexity: `O(N)`, where `N` is the number of nodes in the tree.
- Space Complexity:
    - `O(1)`, since we only use a global variable `ans` to store the max length.
    - But if you consider the call stack, it will be `O(H)`, where `H` is the height of the tree.
## Code
```cpp
class Solution {
public:
    int ans = 0; // Variable ans to store the max zigzag path length
    void dfs(TreeNode* root, bool prev, int cnt = 0) {
        if(!root) return ans = max(ans, cnt), void(); // If root is null, maximize the length and return
        ans = max(ans, cnt); // Maximize the length
        if(prev) { // Come from left
            dfs(root->right, 0, cnt + 1); // Try to go right and increase the length
            dfs(root->left, 1, 0); // Or try to go left and start again from 0
        }
        else { // Come from right
            dfs(root->left, 1, cnt + 1); // Try to go left and increase the length
            dfs(root->right, 0, 0); // Or try to go right and start again from 0
        }
    }

    int longestZigZag(TreeNode* root) {
        dfs(root->left, 1); dfs(root->right, 0); // Call dfs from left and right
        return ans; // Return the max length
    }
};
```