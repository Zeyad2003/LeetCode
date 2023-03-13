class Solution {
public:
    bool isPalindrome(deque<pair<TreeNode*, bool> > &v) {
        int n = (int) v.size();

        for (int i = 0; i < n / 2; ++i) {
            // If both are not null
            if((v[i].first and v[n - i - 1].first)) {
                // Check they are equal in value, and they are not the same side
                if ((v[i].first->val != v[n - i - 1].first->val) or (v[i].second != 1 - v[n - i - 1].second))
                    return false; // If not, return false
            }

                // If one of them is null, return false
            else if((v[i].first and !v[n - i - 1].first) or (!v[i].first and v[n - i - 1].first))
                return false;
        }

        return true; // After looping, the level is palindrome
    }

    bool isSymmetric(TreeNode* root) {
        deque<pair<TreeNode*, bool> > q; // 0 -> left, 1 -> right
        q.emplace_back(root, 0); // Push the root to the queue

        for (int level = 0; !q.empty(); ++level) {
            if(!isPalindrome(q)) return false; // Check if the current level is a palindrome, so it is symmetric
            int sz = (int) q.size(); // Get the size of the current level
            while(sz--) {
                auto curNode = q.front(); // Get the current node
                q.pop_front(); // Pop the current node

                if(!curNode.first) continue; // No need to push null nodes

                q.emplace_back(curNode.first->left, 0); // Push the left child
                q.emplace_back(curNode.first->right, 1); // Push the right child
            }
        }

        return true;
    }
};