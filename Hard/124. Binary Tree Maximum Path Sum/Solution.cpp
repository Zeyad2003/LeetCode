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