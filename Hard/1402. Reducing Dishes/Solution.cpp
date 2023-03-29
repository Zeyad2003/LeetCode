class Solution {
public:
    int dp[505][505]; // dp[i][cnt] -> max satisfaction from i to n - 1 with cnt dishes

    int solve(vector<int> &sat, int i = 0, int cnt = 1) {
        if (i >= (int) sat.size()) return 0; // Finished all dishes

        auto &ret = dp[i][cnt];
        if (~ret) return ret; // Already calculated -> Return it

        ret = -1e9; // Initialize with a very small value
        ret = max(ret, (cnt * sat[i]) + solve(sat, i + 1, cnt + 1)); // Try to take the current dish
        ret = max(ret, solve(sat, i + 1, cnt)); // Skip the current dish
        return ret; // Return the maximum satisfaction
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        memset(dp, -1, sizeof dp); // Initialize dp with -1
        sort(satisfaction.begin(), satisfaction.end()); // Sort the dishes by satisfaction
        return solve(satisfaction); // Call the recursive function
    }
};