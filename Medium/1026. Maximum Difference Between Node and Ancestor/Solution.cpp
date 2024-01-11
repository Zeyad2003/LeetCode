class Solution {
public:
    int ans = 0;

    void update(TreeNode *root, int val) {
        if(!root) return;
        ans = max(ans, (int)abs(root->val - val));
        update(root->left, val);
        update(root->right, val);
    }

    void dfs(TreeNode* root) {
        if(!root) return;
        update(root, root->val);
        dfs(root->left);
        dfs(root->right);
    }

    int maxAncestorDiff(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
