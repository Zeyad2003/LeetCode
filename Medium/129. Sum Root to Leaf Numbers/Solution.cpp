class Solution {
public:
    int sum = 0; // Global variable to add the value of every path

    void dfs(TreeNode* root, string &str) {
        if(!root->left and !root->right) { // If it is a leaf node
            if(str.empty()) sum += root->val; // Only one node so just add its value
            else sum += stoi(str) * 10 + root->val; // Add the value of the path + current node value
            return;
        }
        str.push_back(root->val + '0'); // Add the current node value to the string
        if(root->left) dfs(root->left, str); // If left child exists then call dfs on it
        if(root->right) dfs(root->right, str); // If right child exists then call dfs on it
        str.pop_back(); // Pop the current node when you leave it
    }

    int sumNumbers(TreeNode* root) {
        string tmp; // Temporary string to store the path value
        dfs(root, tmp); // Call dfs on the root node
        return sum; // Return the sum of all the paths
    }
};