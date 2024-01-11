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