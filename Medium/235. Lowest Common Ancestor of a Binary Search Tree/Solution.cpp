class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val == p->val) return p; // Found it first so it's the LCA
        if(root->val == q->val) return q; // Same as above condition
        if((root->val < p->val and root->val > q->val) or (root->val > p->val and root->val < q->val)) return root; // Current root is the LCA
        if(root->val < p->val and root->val < q->val) return lowestCommonAncestor(root->right, p, q); // Move right
        return lowestCommonAncestor(root->left, p, q); // Move left
    }
};