class Solution {
public:

    int build(TreeNode*root, vector<int>& sorted, int k) {
        if(root->left) build(root->left, sorted, k);
        if(sorted.size() == k) return sorted.back();
        sorted.emplace_back(root->val);
        if(root->right) build(root->right, sorted, k);
        return sorted.back();
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> sorted;
        return build(root, sorted, k);
    }
};