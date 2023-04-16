class Solution {
public:
    const int M = 1e9 + 7;
    int freq[1005][26]; // Store the frequency of each character in each column
    int dp[1005][1005]; // dp[i][j] -> number of ways to form target[0..j] using words[0..i]
    int tarSZ, n, m;

    int solve(string &target, int i = 0, int j = 0) {
        if(j == tarSZ) return 1; // We have formed the target -> 1 way
        if(i == m) return 0; // We have reached the end without forming the target -> 0 ways

        auto &ret = dp[i][j];
        if(~ret) return ret; // If we have already calculated the answer -> return it

        ret = solve(target, i + 1, j) % M; // Try to skip the current column

        // Try to use the current column and multiply the number of ways by the frequency of the current character
        ret = ((ret % M) + (long long) freq[i][target[j] - 'a'] * solve(target, i + 1, j + 1)) % M;

        return ret % M; // Return the answer
    }

    int numWays(vector<string>& words, string target) {
        n = (int) words.size(), tarSZ = (int) target.size(), m = (int) words[0].size(); // Initialize the size variables
        memset(freq, 0, sizeof(freq)); // Initialize the frequency array
        memset(dp, -1, sizeof dp); // Initialize the dp array

        for (int col = 0; col < m; col++)
            for (int row = 0; row < n; row++)
                freq[col][words[row][col] - 'a']++; // Count the frequency of each character in each column

        return solve(target); // Return the answer
    }
};