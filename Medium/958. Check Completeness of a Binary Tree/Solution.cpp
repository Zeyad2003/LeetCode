class Solution {
public:
    int cntNodes(TreeNode *root) {
        if(!root) return 0;
        return 1 + cntNodes(root->left) + cntNodes(root->right);
    }

    bool isCompleteTree(TreeNode* root) {
        int cnt = cntNodes(root); // total number of nodes
        queue<TreeNode*> q;
        q.emplace(root); // push root node

        int checkCnt = 0; // number of nodes we have checked
        while(!q.empty()) {
            auto *curNode = q.front(); // get the front node
            q.pop(); // pop the front node

            // if the node is null this means that the number of nodes we have checked is less than the total number of nodes, so the tree is not complete
            if(!curNode) break;

            if(++checkCnt == cnt) return true; // We have checked all the nodes, so the tree is complete
            q.emplace(curNode->left); // push left child
            q.emplace(curNode->right); // push right child
        }

        return false; // the tree is not complete
    }
};