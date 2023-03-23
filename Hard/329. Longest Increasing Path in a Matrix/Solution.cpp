class Solution {

public:
    int dp[205][205]; // dp[i][j] stores the longest increasing path starting from (i, j)
    int dx[4] = {0, 0, 1, -1}; // To move on rows
    int dy[4] = {1, -1, 0, 0}; // To move on columns

    bool out(int n, int m, int i, int j) {
        return i < 0 or j < 0 or i >= n or j >= m;
    }

    int solve(vector<vector<int> > & v, int n, int m, int i, int j) {
        if(out(n, m, i, j)) return 0; // If we are out of the grid then return 0

        auto & ret = dp[i][j];
        if(~ret) return ret; // If we have already calculated the answer then return it

        ret = 0;
        for(int idx = 0; idx < 4; idx++) { // Try all the 4 directions
            int nx = dx[idx] + i;
            int ny = dy[idx] + j;
            if(!out(n, m, nx, ny) and v[i][j] < v[nx][ny]) // If it valid cell
                ret = max(ret, 1 + solve(v, n, m, nx, ny)); // Take the maximum of all the 4 directions
        }

        return ret; // Return the answer
    }

    int longestIncreasingPath(vector<vector<int> >& matrix) {
        memset(dp, -1, sizeof dp); // Initialize the dp array with -1
        int n = (int)matrix.size(), m = (int)matrix[0].size(); // Get the size of the grid
        int ans = 0; // Initialize the answer with 0

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, 1 + solve(matrix, n, m, i, j)); // Try to start from every cell and take the maximum answer
            }
        }

        return ans; // Return the answer
    }
};