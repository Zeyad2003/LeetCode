class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        long long M = 1e10;
        map<TreeNode*, long long> mp;
        queue<TreeNode*> q;
        q.emplace(root);
        mp[root] = 0;
        int ans = 0;
        for(int level = 0; !q.empty(); level++) {
            int sz = (int) q.size();
            vector<TreeNode*> v;
            while(sz--) {
                auto *curNode = q.front();
                auto idx = mp[curNode];
                q.pop();
                v.emplace_back(curNode);
                if(curNode->left) {
                    mp[curNode->left] = (2 * idx + 1) % M;
                    q.emplace(curNode->left);
                }
                if(curNode->right) {
                    mp[curNode->right] = (2 * idx + 2) % M;
                    q.emplace(curNode->right);
                }
            }
            int val = mp[v.back()] - mp[v[0]] + 1;
            ans = max(ans, val);
        }
        return ans;
    }
};