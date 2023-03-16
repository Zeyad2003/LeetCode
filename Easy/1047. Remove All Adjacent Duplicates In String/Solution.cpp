class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st; // Create a stack to store the characters
        for(auto & i : s) { // Iterate over the string
            if(!st.empty()) { // If the stack is not empty
                bool f = false; // Create a flag to check if the current character is equal to the top of the stack
                while(!st.empty() and st.top() == i) { // While having the same character
                    st.pop(); // Pop the top of the stack
                    f = true; // Set the flag to true
                }
                if(f) continue; // If the flag is true, continue to the next character without pushing it to the stack.
            }
            st.emplace(i); // If the stack is empty or the top of the stack is not equal to the current character, push it to the stack
        }
        string ans;
        while(!st.empty()) ans.push_back(st.top()), st.pop(); // Pop the stack and add the characters to the answer string
        reverse(ans.begin(), ans.end()); // Reverse the answer string
        return ans; // Return the answer string
    }
};