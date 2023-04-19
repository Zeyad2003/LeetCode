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