class Solution {
public:

    int dp[51];
    const int MX = 100;

    int solve(string & s, vector<string> &dictionary, int i = 0) {
        if(i >= (int) s.size()) return 0;

        auto & ret = dp[i];
        if(~ret) return ret;

        ret = MX;

        ret = min(ret, solve(s, dictionary, i + 1) + 1);
        for(auto & word : dictionary) {
            int wordSize = (int) word.size();
            string sub = s.substr(i, wordSize);
            if(sub == word)
                ret = min(ret, solve(s, dictionary, i + wordSize));
        }

        return ret;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        memset(dp, -1, sizeof dp);
        return solve(s, dictionary);
    }
};