class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = (int) word1.size(), m = (int) word2.size();
        string ans; // Concatenation of word1 and word2
        int i = 0, j = 0; // Pointers to word1 and word2

        while(i < n and j < m) { // Merge word1 and word2
            ans.push_back(word1[i++]);
            ans.push_back(word2[j++]);
        }

        while(i < n) ans.push_back(word1[i++]); // Add remaining characters of word1
        while(j < m) ans.push_back(word2[j++]); // Add remaining characters of word2
        return ans;
    }
};