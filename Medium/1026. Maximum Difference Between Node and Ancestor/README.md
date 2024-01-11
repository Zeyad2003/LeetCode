# [1026. Maximum Difference Between Node and Ancestor](https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/)

## Solution:
- We know the max number of nodes in the tree will be up to `5000`, so we can go up to `O(n ^ 2)` solution.
- We use **`DFS`** to explore every node in the tree, and for each node, we can use **`DFS`** again to explore all the childs of the node, and calculate the max difference. 

## Complexity
- Time Complexity: `O(n ^ 2)`, where `n` is the length of nodes in the tree.

- Space Complexity: `O(h)`, where `h` is the height of the tree (the max depth of the tree) for the call stack.

## Code
### C++
```cpp
class Solution {
public:
    int ans = 0;

    void update(TreeNode *root, int val) {
        if(!root) return;
        ans = max(ans, (int)abs(root->val - val));
        update(root->left, val);
        update(root->right, val);
    }

    void dfs(TreeNode* root) {
        if(!root) return;
        update(root, root->val);
        dfs(root->left);
        dfs(root->right);
    }

    int maxAncestorDiff(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
```

### Java
```java
class Solution {
    int ans = 0;

    void update(TreeNode root, int val) {
        if(root == null) return;
        ans = Math.max(ans, Math.abs(root.val - val));
        update(root.left, val);
        update(root.right, val);
    }

    void dfs(TreeNode root) {
        if(root == null) return;
        update(root, root.val);
        dfs(root.left);
        dfs(root.right);
    }

    public int maxAncestorDiff(TreeNode root) {
        dfs(root);
        return ans;
    }
}
```

### JavaScript
```javascript
let ans;

let update = (root, val) => {
    if(root === null) return;
    ans = Math.max(ans, Math.abs(root.val - val));
    update(root.left, val);
    update(root.right, val);
};

let dfs = (root) => {
    if(root === null) return;
    update(root, root.val);
    dfs(root.left);
    dfs(root.right);
};

var maxAncestorDiff = function (root) {
    ans = 0;
    dfs(root);
    return ans;
};
```

### Python
```python
class Solution(object):
    def __init__(self):
        self.ans = 0

    def update(self, root, val):
        if root == None: return
        self.ans = max(self.ans, abs(root.val - val))
        self.update(root.left, val)
        self.update(root.right, val)

    def dfs(self, root):
        if root == None: return
        self.update(root, root.val)
        self.dfs(root.left)
        self.dfs(root.right)

    def maxAncestorDiff(self, root):
        self.ans = 0
        self.dfs(root)
        return self.ans
```
