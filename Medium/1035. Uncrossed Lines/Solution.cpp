class Solution {
public:
    int dp[501][501];
    int n, m;

    int solve(vector<int> &first, vector<int> &second, int i = 0, int j = 0) {
        if(i >= n or j >= m) return 0;

        auto & ret = dp[i][j];
        if(~ret) return ret;

        ret = solve(first, second, i + 1, j);
        ret = max(ret, solve(first, second, i, j + 1));
        if(first[i] == second[j])
            ret = max(ret, 1 + solve(first, second, i + 1, j + 1));

        return ret;
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        n = (int) nums1.size(), m = (int) nums2.size();
        memset(dp, -1, sizeof dp);
        return solve(nums1, nums2);
    }
};