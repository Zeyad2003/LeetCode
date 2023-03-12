class Solution {
public:
    string freqAlphabets(string s) {
        int n = (int) s.size();
        string ret;
        for(int i = 0; i < n; i++) {
            if(i + 2 < n and s[i + 2] == '#') { // 10# - 26#
                int x = (s[i] - '0') * 10 + (s[i + 1] - '0'); // Get the number
                ret += (char) (x + 'a' - 1); // Add the character
                i += 2; // Skip the next two characters
            } else {
                ret += (char) (s[i] - '0' + 'a' - 1); // Add the character
            }
        }
        return ret; // Return the answer
    }
};