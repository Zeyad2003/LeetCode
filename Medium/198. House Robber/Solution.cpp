class Solution {
public:

    int rob(vector<int> &nums) {
        int sz = (int) nums.size();
        int dp[101];
        memset(dp, -1, sizeof dp);

        function<int(int)> solve = [&](int i) {
            if (i >= sz) return 0;
            if (~dp[i]) return dp[i];
            return dp[i] = max(solve(i + 1), nums[i] + solve(i + 2));
        };

        return solve(0);
    }
};
