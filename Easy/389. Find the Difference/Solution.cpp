class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = (int) s.size();
        int m = (int) t.size();
        int sum = 0;

        for(int i = 0; i < n; i++) // Add every character to sum of s
            sum += s[i];

        for(int i = 0; i < m; i++) // Subtract every character from sum of t
            sum -= t[i];

        return (char) abs(sum); // The difference is the missing character
    }
};