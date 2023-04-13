class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = (int) pushed.size(); // Get the size of the array
        int idx = 0; // To keep track of the popped array
        stack<int> st; // To keep track of the pushed array

        for(int i = 0; i < n; i++) { // Iterate over the pushed array
            st.push(pushed[i]); // Push the element into the stack
            while(!st.empty() and st.top() == popped[idx]) { // While top of the stack is equal to the popped array
                st.pop(); // Pop the element
                idx++; // Increment the index
            }
        }

        return st.empty(); // If the stack is empty, then the popped array is a valid sequence
    }
};