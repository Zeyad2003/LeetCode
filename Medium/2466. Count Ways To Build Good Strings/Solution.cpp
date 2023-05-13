class Solution {
public:
    const int M = 1e9 + 7;
    vector<int> dp;
    int solve(int val, int low, int high, int zero, int one) {
        if(val > high) return 0;

        auto & ret = dp[val];
        if(~ret) return ret;

        if(val >= low) {
            return ret = 1 + ((solve(val + zero, low, high, zero, one) % M) + (solve(val + one, low, high, zero, one) % M)) % M;
        }

        return ret = ((solve(val + zero, low, high, zero, one) % M) + (solve(val + one, low, high, zero, one) % M)) % M;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        dp = vector<int>(high + 1, -1);
        return solve(0, low, high, zero, one);
    }
};