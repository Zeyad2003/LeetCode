class Solution {
    final int M = 1000000007;
    int[] dp;

    int solve(int val, int low, int high, int zero, int one) {
        if(val > high) return 0;

        if(dp[val] != -1) return dp[val];

        if(val >= low)
            return dp[val] = 1 + ((solve(val + zero, low, high, zero, one) % M) + (solve(val + one, low, high, zero, one) % M)) % M;

        return dp[val] = ((solve(val + zero, low, high, zero, one) % M) + (solve(val + one, low, high, zero, one) % M)) % M;
    }

    public int countGoodStrings(int low, int high, int zero, int one) {
        dp = new int[high + 1];
        Arrays.fill(dp, -1);
        return solve(0, low, high, zero, one);
    }
}