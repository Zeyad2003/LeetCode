class Solution {
    int dp[205][205]; // dp[i][j] = min cost to reach (i, j) from (0, 0)
    const static int oo = INT_MAX; // infinity
    int n, m; // The size of the grid
public:

    int solve(vector<vector<int> > & arr, int i = 0, int j = 0) { // Calculate the minimum sum to reach (n - 1, m - 1) from (0, 0)
        if(i == n - 1 and j == m - 1) return arr[i][j]; // Reach the destination -> Return the cost of the cell

        auto & ret = dp[i][j];
        if(~ret) return ret; // If the state is calculated before -> Return the answer

        ret = oo; // Initialize the answer with infinity
        if(i + 1 < n) // If we can move to the next row
            ret = min(ret, arr[i][j] + solve(arr,i + 1, j)); // Try it
        if(j + 1 < m) // If we can move to the next column
            ret = min(ret, arr[i][j] + solve(arr,i, j + 1)); // Try it
        return ret; // Return the minimum answer
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof dp); // Initialize the dp array with -1
        n = (int)grid.size();
        m = (int)grid[0].size();
        return solve(grid); // Return the answer
    }
};
