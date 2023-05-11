class Solution {
    public int n, m;
    int dp[][] = new int[501][501];

    int solve(int[] first, int[] second, int i, int j) {
        if(i >= n || j >= m) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ret = solve(first, second, i + 1, j);
        ret = Math.max(ret, solve(first, second, i, j + 1));
        if(first[i] == second[j])
            ret = Math.max(ret, 1 + solve(first, second, i + 1, j + 1));

        return dp[i][j] = ret;
    }

    public int maxUncrossedLines(int[] nums1, int[] nums2) {
        n = nums1.length; m = nums2.length;

        for (int[] i : dp) Arrays.fill(i, -1);

        return solve(nums1, nums2, 0, 0);
    }
}