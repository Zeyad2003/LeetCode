class Solution {
    boolean out(int i, int j, int n) {
        return i < 0 || i >= n || j < 0 || j >= n;
    }

    void dfs(int[][] ans, boolean[][] vis, int n, int i, int j, int val) {
        if(out(i, j, n) || vis[i][j]) return;
        vis[i][j] = true;
        ans[i][j] = val;

        if((i > 0 && vis[i - 1][j] ) || i == 0)
            dfs(ans, vis, n, i, j + 1, val + 1);
        dfs(ans, vis, n, i + 1, j, val + 1);
        dfs(ans, vis, n, i, j - 1, val + 1);
        dfs(ans, vis, n, i - 1, j, val + 1);
    }

    public int[][] generateMatrix(int n) {
        int[][] ans = new int[n][n];
        boolean[][] vis = new boolean[n][n];
        dfs(ans, vis, n, 0, 0, 1);
        return ans;
    }
}