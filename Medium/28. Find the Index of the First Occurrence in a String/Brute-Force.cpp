// Zeyad Nasef
class Solution {
public:

    int strStr(string haystack, string needle) {
        int n = (int) haystack.size(), m = (int) needle.size();

        for(int i = 0; i <= n - m; i++) { // loop over the last valid index we can start comparing from
            int j = 0;
            for(; j < m; j++) { // loop over the pattern
                if(haystack[i + j] != needle[j]) break;
            }
            if(j == m) return i; // we found the pattern
        }

        return -1;
    }
};