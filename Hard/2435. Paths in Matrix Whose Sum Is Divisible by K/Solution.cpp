class Solution {
    int n, m, K;
    const int M = 1e9 + 7;
    vector<vector<vector<int> > > dp; // dp[i][j][sum] = number of paths from (0, 0) to (i, j) with sum % k = sum
public:
    int solve(vector<vector<int> > & v, int i, int j, int sum) {
        if(i == n - 1 and j == m - 1) return (sum % K == 0); // if you reached the end check if the sum is divisible by k

        auto & ret = dp[i][j][sum];
        if(~ret) return ret; // if you already calculated the answer return it

        ret = 0;
        if(i + 1 < n) ret = (((ret % M) + (solve(v, i + 1, j, (sum + v[i + 1][j]) % K) % M)) % M); // try to go down
        if(j + 1 < m) ret = (((ret % M) + (solve(v, i, j + 1, (sum + v[i][j + 1]) % K) % M)) % M); // try to go right
        return ret; // return the answer
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        K = k;
        n = (int)grid.size();
        m = (int)grid[0].size();
        dp = vector<vector<vector<int> > > (n, vector<vector<int> >(m, vector<int>(200, -1))); // Initialize the dp array
        return solve(grid, 0, 0, grid[0][0]);
    }
};