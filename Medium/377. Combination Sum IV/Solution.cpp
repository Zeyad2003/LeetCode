class Solution {
public:

    int combinationSum4(vector<int>& nums, int target) {
        int dp[target];
        memset(dp, -1, sizeof dp);
        function<int(int)> solve = [&](int val) -> int {
            if(val > target) return 0;
            if(val == target) return 1;

            auto & ret = dp[val];
            if(~ret) return ret;

            ret = 0;
            for(auto & it : nums)
                ret += solve(val + it);
            return ret;
        };
        return solve(0);
    }
};