class Solution {
    final int M = 1000000007, N = 105;
    int [][][]dp = new int[N][N][N];
    int sz;

    int solve(int []group, int []profit, int n, int minProfit, int i) {
        if(n < 0) return 0;
        if(i >= sz) return minProfit <= 0 ? 1 : 0;

        if(minProfit < 0) minProfit = 0; // Handle out of bound
        if(dp[i][n][minProfit] != -1) return dp[i][n][minProfit];

        int ret = 0;

        ret = ((ret % M) + (solve(group, profit, n, minProfit, i + 1) % M)) % M;
        ret = ((ret % M) + (solve(group, profit, n - group[i], minProfit - profit[i], i + 1) % M)) % M;

        return dp[i][n][minProfit] = ret;
    }

    public int profitableSchemes(int n, int minProfit, int[] group, int[] profit) {
        sz = group.length;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        return solve(group, profit, n, minProfit, 0);
    }
}