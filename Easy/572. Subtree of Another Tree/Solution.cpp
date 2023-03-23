class Solution {
public:

    string flatten(TreeNode *root) { // Flatten the tree and add ',' to mark every position of the nodes
        if(!root) return ",";
        return "," + to_string(root->val) + "," + flatten(root->left) + "," + flatten(root->right) + ",";
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string str = flatten(root); // Flatten the tree
        string sub = flatten(subRoot); // Flatten the subtree
        return str.find(sub) != string::npos; // Check if sub is exist inside the str -> root
    }
};