class Solution {

    public int[][] dp;

    public boolean out(int m, int n, int i, int j) {
        return i < 0 || j < 0 || i >= m || j >= n;
    }

    public int solve(int m, int n, int i, int j) {
        if (i == m - 1 && j == n - 1)
            return 1;

        int ret = dp[i][j];
        if (ret != -1)
            return ret;

        ret = 0;
        if (!out(m, n, i + 1, j))
            ret += solve(m, n, i + 1, j);
        if (!out(m, n, i, j + 1))
            ret += solve(m, n, i, j + 1);
        return dp[i][j] = ret;
    }

    public int uniquePaths(int m, int n) {
        dp = new int[m][n];
        Arrays.stream(dp).forEach(arr -> Arrays.fill(arr, -1));
        return solve(m, n, 0, 0);
    }
}