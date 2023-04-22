class Solution {
    int [][] dp = new int[505][505];

    int solve(String s, int l, int r) {
        if(l >= r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        if(s.charAt(l) == s.charAt(r)) return dp[l][r] = solve(s, l + 1, r - 1);
        return dp[l][r] = 1 + Math.min(solve(s, l + 1, r), solve(s, l, r - 1));
    }

    public int minInsertions(String s) {
        for (int i = 0; i < 505; i++) {
            for (int j = 0; j < 505; j++) {
                dp[i][j] = -1;
            }
        }
        return solve(s, 0, s.length() - 1);
    }
}