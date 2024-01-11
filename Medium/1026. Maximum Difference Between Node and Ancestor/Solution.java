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