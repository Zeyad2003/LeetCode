import java.util.Arrays;

class Solution {
    int[] dp;

    int solve(int[] nums, int target, int val) {
        if (val > target)
            return 0;
        if (val == target)
            return 1;

        if (dp[val] != -1)
            return dp[val];

        int ret = 0;
        for (int it : nums)
            ret += solve(nums, target, val + it);
        return dp[val] = ret;
    }

    public int combinationSum4(int[] nums, int target) {
        dp = new int[target];
        Arrays.fill(dp, -1);

        return solve(nums, target, 0);
    }
}