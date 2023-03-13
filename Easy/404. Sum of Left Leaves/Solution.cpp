class Solution {
public:
    int dfs(TreeNode* root, bool side = 0) {
        if(!root) return 0; // if root is null return 0
        if(!root->left and !root->right and side) // We are at a leaf on the left side so return its value
            return root->val;

        int left = dfs(root->left, 1); // Calculate the left side
        int right = dfs(root->right, 0); // Calculate the right side

        return left + right; // Return their sum
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root); // Call the dfs function and return its value
    }
};