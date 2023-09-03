class Solution {
private:
    int dp[105][105];
public:
    Solution() { memset(dp, -1, sizeof dp); }
    bool out(int m, int n, int i, int j) { return i < 0 or j < 0 or i >= m or j >= n; }
    int solve(int m, int n, int i = 0, int j = 0) {
        if(i == m - 1 and j == n - 1) return 1;

        auto & ret = dp[i][j];
        if(~ret) return ret;

        ret = 0;
        if(!out(m, n, i + 1, j)) ret += solve(m, n, i + 1, j);
        if(!out(m, n, i, j + 1)) ret += solve(m, n, i, j + 1);
        return ret;
    }
    int uniquePaths(int m, int n) {
        return solve(m, n);
    }
};