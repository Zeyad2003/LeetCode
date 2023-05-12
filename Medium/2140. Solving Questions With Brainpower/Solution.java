class Solution {
    long[] dp = new long[100001];

    long solve(int[][] questions, int i) {
        if(i >= questions.length) return 0;
        if(dp[i] != -1) return dp[i];

        long ret = solve(questions, i + 1);
        ret = Math.max(ret, questions[i][0] + solve(questions, i + questions[i][1] + 1));

        return dp[i] = ret;
    }

    public long mostPoints(int[][] questions) {
        Arrays.fill(dp, -1);
        return solve(questions, 0);
    }
}