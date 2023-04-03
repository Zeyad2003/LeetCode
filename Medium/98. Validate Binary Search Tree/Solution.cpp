class Solution {
public:
    long long oo = 1e12; // Big value to avoid overflow
    bool valid(TreeNode *root, long long mx, long long mn) {
        if(!root) return true; // We reach the end of the tree, and it is valid until now
        if(root->val <= mn or root->val >= mx) return false; // The current node is not valid -> Return false
        return valid(root->left, root->val, mn) and valid(root->right, mx, root->val); // Check the left and right subtrees
    }

    bool isValidBST(TreeNode* root) {
        return valid(root, oo, -oo); // Call the function with the big values
    }
};