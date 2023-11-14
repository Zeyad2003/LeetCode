class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> st;
        int n = (int) s.size(), ans = 0;

        for(int i = 0; i < n; i++) {
            if(st.find(s[i]) == st.end()) {
                st.emplace(s[i]);
                int lastIdx = (int) s.find_last_of(s[i]);
                if(lastIdx != i) {
                    unordered_set<char> cntDistinct(s.begin() + i + 1, s.begin() + lastIdx);
                    ans += (int) cntDistinct.size();
                }
            }
        }

        return ans;
    }
};
