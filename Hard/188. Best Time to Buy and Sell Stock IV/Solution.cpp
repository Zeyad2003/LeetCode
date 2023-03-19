class Solution {
    const static int N = 1e3 + 5; // max number of days
    const static int K = 1e2 + 5; // max number of transactions
    int dp[N][K][2];
public:
    int solve(vector<int> &prices, int n, int idx, int rem, bool took) {
        if(idx >= n or !rem) return 0; // finish the array or no more transactions allowed

        auto & ret = dp[idx][rem][took];
        if(~ret) return ret; // if already calculated -> return it

        ret = solve(prices, n, idx + 1, rem, took); // skip the current stock
        if(!took)
            ret = max(ret, solve(prices, n, idx + 1, rem, 1) - prices[idx]); // buy the current stock
        else
            ret = max(ret, solve(prices, n, idx + 1, rem - 1, 0) + prices[idx]); // sell the current stock

        return ret; // return the maximum profit he can get
    }
    int maxProfit(int k, vector<int>& prices) {
        if(is_sorted(prices.rbegin(), prices.rend())) return 0; // if sorted in descending order -> best solution is 0
        memset(dp, -1, sizeof(dp)); // initialize dp with -1
        return solve(prices, (int)prices.size(), 0, k, 0); // call solve function to calculate the optimal answer
    }
};