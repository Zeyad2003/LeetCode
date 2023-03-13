class Solution {
public:
    int depth = 0; // Variable to calculate the max depth of the tree

    void dfs(TreeNode* root, int d = 1) {
        if(!root) return; // We reach the end of the tree
        depth = max(depth, d); // Update with the max depth we reach until now
        dfs(root->left, d + 1); // Check the left subtree
        dfs(root->right, d + 1); // Check the right subtree
    }

    int maxDepth(TreeNode* root) {
        if(!root) return 0; // No nodes no depth
        dfs(root); // Start the recursion
        return depth; // Return the max depth we reached
    }
};