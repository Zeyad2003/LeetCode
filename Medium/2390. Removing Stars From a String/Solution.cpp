class Solution {
public:
    string removeStars(string s) {
        stack<char> st; // store the characters in the string
        for(auto & i : s) { // loop through the string
            if(i != '*') st.emplace(i); // Not a star -> Push it to the stack
            else st.pop(); // Star -> Pop the nearest to it (top of the stack)
        }

        string ans; // To store the answer
        while(!st.empty()) { // Put the characters in the stack to the answer
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end()); // Reverse the string
        return ans; // Return the answer
    }
};