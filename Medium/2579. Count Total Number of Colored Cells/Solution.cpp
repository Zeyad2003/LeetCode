class Solution {
public:
    long long coloredCells(int n) {
        vector<pair<long long, long long> > dp(n + 1); // <level, numberOfCells>
        dp[1] = {1, 1}; // Base Case -> level 1, 1 cell
        for(int i = 2; i <= n; i++) { // Loop until reaching level n
            auto [level, numberOfCells] = dp[i - 1]; // Get the previous level
            numberOfCells += (level << 1) + 2; // Calculate the number of new cells that will be added then add it to the next cell.
            level += 2; // Increase the level by 2
            dp[i] = {level, numberOfCells}; // Save the result
        }
        return dp[n].second; // Return the number of cells in level n
    }
};