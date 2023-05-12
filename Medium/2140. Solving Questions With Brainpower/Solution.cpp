class Solution {
public:
    long long dp[100001];

    long long solve(vector<vector<int> > &questions, int i = 0) {
        if(i >= (int) questions.size()) return 0;

        auto & ret = dp[i];
        if(~ret) return ret;

        ret = solve(questions, i + 1);
        ret = max(ret, questions[i][0] + solve(questions, i + questions[i][1] + 1));

        return ret;
    }

    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp, -1, sizeof dp);
        return solve(questions);
    }
};