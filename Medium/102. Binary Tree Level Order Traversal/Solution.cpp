class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q; // Used to store every level nodes
        q.emplace(root); // Put the root node
        vector<vector<int> > ans; // Used to store the vector of every level
        if(!root) return ans; // No root -> No levels to traverse

        for(int level = 0; !q.empty(); level++) { // For every level
            int sz = (int) q.size(); // Get the size of the current level
            vector<int> tmp; // To store the current level values
            while(sz--) {
                auto curNode = q.front(); // Get the current node
                q.pop(); // Remove it from the queue
                tmp.emplace_back(curNode->val); // Put the value of the current node
                if(curNode->left) q.emplace(curNode->left); // If it has a left node push it
                if(curNode->right) q.emplace(curNode->right); // If it has a right node push it
            }
            ans.emplace_back(tmp); // Finally push the current level values to ans
        }
        return ans; // Return your final answer
    }
};