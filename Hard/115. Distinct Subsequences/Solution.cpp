class Solution {
public:
    int dp[1001][1001]; // dp[i][j] = number of distinct subsequences of s[i..n] and t[j..m]
    int n, m; // the size of s and t

    int solve(string &s, string &t, int i, int j) {
        if(j >= m) return 1; // If we reached the end of t, then there is only one distinct subsequence
        if(i >= n) return 0; // If we reached the end of s, then there is no distinct subsequence

        auto & ret = dp[i][j];
        if(~ret) return ret; // If we already calculated the answer, then return it

        ret = 0; // Initialize the answer with 0

        ret += solve(s, t, i + 1, j); // Skip the current character in s
        if(s[i] == t[j]) // If the current character in s is equal to the current character in t
            ret += solve(s, t, i + 1, j + 1); // Take the current character in s

        return ret; // Return the number of distinct subsequences
    }

    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof (dp)); // Initialize the dp array with -1
        n = (int) s.size(), m = (int) t.size(); // Initialize the size of s and t
        return solve(s, t, 0, 0); // Return the number of distinct subsequences
    }
};