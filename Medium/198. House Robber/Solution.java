class Solution {
    public int rob(int[] nums) {
        int sz = nums.length;
        int[] dp = new int[101];
        Arrays.fill(dp, -1);

        Function<Integer, Integer> solve = new Function<Integer, Integer>() {

            public Integer apply(Integer i) {
                if (i >= sz) return 0;
                if (dp[i] != -1) return dp[i];
                return dp[i] = Math.max(apply(i + 1), nums[i] + apply(i + 2));
            }
        };
        return solve.apply(0);
    }
}
