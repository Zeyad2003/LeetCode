class Solution {
public:
    int dp[505][505];

    int solve(string &s, int l, int r) {
        if(l >= r) return 0;

        auto & ret = dp[l][r];
        if(~ret) return ret;

        if(s[l] == s[r]) ret = solve(s, l + 1, r - 1);
        else ret = 1 + min(solve(s, l + 1, r), solve(s, l, r - 1));
        return ret;
    }

    int minInsertions(string s) {
        memset(dp, -1, sizeof dp);
        return solve(s, 0, (int) s.size() - 1);
    }
};