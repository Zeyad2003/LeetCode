class Solution {
public:
    int n;

    int solve(vector<int> &arr, int mask, int i, int dp[][8]) {
        if(i > n) return 0;

        auto & ret = dp[mask][i];
        if(~ret) return ret;

        ret = 0;

        for(int bt1 = 0; bt1 < (n << 1); bt1++) {
            for(int bt2 = bt1 + 1; bt2 < (n << 1); bt2++) {
                int firstPlace = (mask & (1 << bt1)) != 0;
                int secondPlace = (mask & (1 << bt2)) != 0;
                if(firstPlace and secondPlace)
                    ret = max(ret, i * gcd(arr[bt1], arr[bt2]) + solve(arr, mask & ~(1 << bt1) & ~(1 << bt2), i + 1, dp));
            }
        }

        return ret;
    }

    int maxScore(vector<int> &nums) {
        n = (int) nums.size();
        int dp[1 << n][8];
        memset(dp, -1, sizeof dp);
        int mask = (1 << n) - 1;
        n >>= 1;
        return solve(nums, mask, 1, dp);
    }
};