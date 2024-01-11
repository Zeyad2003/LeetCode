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

