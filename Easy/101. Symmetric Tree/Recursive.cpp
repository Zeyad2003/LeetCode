class Solution {
public:

    bool check(TreeNode* root1, TreeNode* root2) {
        if(!root1 and !root2) // If both are null, we reached the end of the tree
            return true;

        if(root1 and root2 and root1->val == root2->val) // If both are not null, check if they are equal
            return check(root1->left, root2->right) & check(root1->right, root2->left); // Then, check the left subtree and the right subtree

        return false; // If they are not equal, return false
    }

    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right); // Check the left subtree and the right subtree
    }
};