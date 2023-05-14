class Solution {
    public int n;
    public int [][] dp;

    public int gcd(int a, int b) {
        if (b == 0) return a;
        else return gcd(b, a % b);
    }

    int solve(int[] arr, int mask, int i) {
        if(i > n) return 0;

        if(dp[mask][i] != -1) return dp[mask][i];

        int ret = 0;

        for(int bt1 = 0; bt1 < (n << 1); bt1++) {
            for(int bt2 = bt1 + 1; bt2 < (n << 1); bt2++) {
                int firstPlace = (mask & (1 << bt1));
                int secondPlace = (mask & (1 << bt2));
                if(firstPlace != 0 && secondPlace != 0)
                    ret = Math.max(ret, i * gcd(arr[bt1], arr[bt2]) + solve(arr, mask & ~(1 << bt1) & ~(1 << bt2), i + 1));
            }
        }

        return dp[mask][i] = ret;
    }

    public int maxScore(int[] nums) {
        n = nums.length;
        dp = new int[1 << n][8];
        for(int[] i : dp) Arrays.fill(i, -1);
        int mask = (1 << n) - 1;
        n >>= 1;
        return solve(nums, mask, 1);
    }
}