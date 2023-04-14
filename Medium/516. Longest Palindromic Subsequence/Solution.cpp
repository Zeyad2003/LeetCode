class Solution {
public:
    const static int N = 1e3 + 5; // Max length of the string
    int dp[N][N]; // dp[i][j] = the length of the longest palindromic subsequence from i to j

    int solve(string &s, int i, int j) {
        if(i > j) return 0; // Base case
        if(i == j) return 1; // There's only one character

        auto & ret = dp[i][j];
        if(~ret) return ret; // If the state is already calculated, return it

        ret = 0; // Initialize the answer with a minimum value
        if(s[i] == s[j]) ret = max(ret, 2 + solve(s, i + 1, j - 1)); // If the 2 characters are equal, we can add them to the answer
        ret = max(ret, solve(s, i + 1, j)); // Try to remove the first character
        ret = max(ret, solve(s, i, j - 1)); // Try to remove the last character
        return ret; // Return the maximum answer
    }

    int longestPalindromeSubseq(string s) {
        memset(dp, -1, sizeof dp); // Initialize the dp array with -1
        return solve(s, 0, (int) s.size() - 1); // Return the answer
    }
};