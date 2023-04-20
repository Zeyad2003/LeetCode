# [662. Maximum Width of Binary Tree](https://leetcode.com/problems/maximum-width-of-binary-tree/)

## Solution
- Use `BFS` to traverse the tree level by level.
- For every node use a map and assign an index to its children, which is `2 * idx + 1` for the left child and `2 * idx + 2` for the right child.
- Wath out for the overflow of the index, so use `long long` and `1e10` as the modulo.
- Store the nodes for every level in a vector and calculate the width of this level
- the width will equal `index of the last node - index of the first node + 1` -> `mp[v.back()] - mp[v[0]] + 1`
- Update the global variable `ans` with the maximum width.
- Finally, return the `ans`.
## Complexity
- Time Complexity: `O(Nlog(n))`, where `N` is the number of nodes in the tree.
- Space Complexity: `O(N)`, for the map and the queue.

## Code
```cpp
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
```

```java
import java.util.*;
class Solution {
    public int widthOfBinaryTree(TreeNode root) {
        long M = 10000000000L;
        Map<TreeNode, Long> mp = new HashMap<>();
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        mp.put(root, 0L);
        int ans = 0;
        for(int level = 0; !q.isEmpty(); level++) {
            int sz = q.size();
            Vector<TreeNode> v = new Vector<>();
            for(int i = 0; i < sz; i++){
                TreeNode curNode = q.peek();
                long idx = mp.get(curNode);
                q.remove();
                v.add(curNode);
                if(curNode.left != null) {
                    mp.put(curNode.left, (2 * idx + 1) % M);
                    q.add(curNode.left);
                }
                if(curNode.right != null) {
                    mp.put(curNode.right, (2 * idx + 2) % M);
                    q.add(curNode.right);
                }
            }
            
            int val = (int) (mp.get(v.get(v.size() - 1)) - mp.get(v.get(0))) + 1;
            ans = Math.max(ans, val);
        }
        return ans;
    }
}
```