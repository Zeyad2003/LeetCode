class Solution {
public:
    string toLowerCase(string s) {
        for(auto & i : s)
            i = (char) tolower(i); // Use tolower() function
        return s;
    }
};