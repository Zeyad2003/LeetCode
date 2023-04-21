class Solution {
public:
    int sz;
    const static int N = 105, M = 1e9 + 7;
    int dp[N][N][N];

    int solve(vector<int> &group, vector<int> &profit, int n, int minProfit, int i = 0) {
        if(n < 0) return 0;
        if(i >= sz) return minProfit <= 0;

        if(minProfit <= 0) minProfit = 0; // Handle out of bound
        auto & ret = dp[i][n][minProfit];
        if(~ret) return ret;

        ret = 0;

        ret = ((ret % M) + (solve(group, profit, n, minProfit, i + 1) % M)) % M; // Leave
        ret = ((ret % M) + (solve(group, profit, n - group[i], minProfit - profit[i], i + 1) % M)) % M; // Take

        return ret;
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        sz = (int) group.size();
        memset(dp, -1, sizeof(dp));
        return solve(group, profit, n, minProfit);
    }
};