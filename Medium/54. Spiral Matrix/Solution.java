class Solution {
    public int n, m;

    boolean out(int i, int j) {
        return i < 0 || i >= n || j < 0 || j >= m;
    }

    public void solve(int[][] matrix, boolean[][] vis, int i, int j, List<Integer> ans) {
        if(out(i, j) || vis[i][j]) return;
        vis[i][j] = true;
        ans.add(matrix[i][j]);

        if((i > 0 && vis[i - 1][j]) || i == 0)
            solve(matrix, vis, i, j + 1, ans);
        solve(matrix, vis, i + 1, j, ans);
        solve(matrix, vis, i, j - 1, ans);
        solve(matrix, vis, i - 1, j, ans);
    }

    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ans = new ArrayList<>();
        n = matrix.length;
        m = matrix[0].length;
        boolean[][] vis = new boolean[n][m];
        solve(matrix, vis, 0, 0, ans);
        return ans;
    }
}