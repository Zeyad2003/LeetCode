// Zeyad Nasef
class Solution {
public:

    // build the prefix array for the pattern
    vector<int> build(string &pat) {
        int n = (int) pat.size();
        int i = 1, j = 0;
        vector<int> v(n, 0);

        while (i < n) {
            if (pat[i] == pat[j]) v[i++] = ++j;

            else if (j > 0) j = v[j - 1];

            else i++;
        }

        return v;
    }

    int strStr(string haystack, string needle) {
        vector<int> patTable = build(needle);

        int n = (int) haystack.size(), m = (int) needle.size();

        int i = 0, j = 0;
        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++, j++; // move to the next character
                if (j == m) return i - j; // we found the pattern
            }
            else if (j > 0) j = patTable[j - 1]; // go to the first index that matches the prefix of the pattern
            else i++; // move to the next character in the string
        }

        return -1;
    }
};