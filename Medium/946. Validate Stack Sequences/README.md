# [946. Validate Stack Sequences](https://leetcode.com/problems/validate-stack-sequences/)

## Solution
- Use a stack to keep track of the pushed array.
- Iterate over the pushed array.
- Push the element into the stack.
- While the top of the stack is equal to the popped array, pop the element and increment the index.
- If the stack is empty, then the popped array is a valid sequence.

## Complexity
- Time Complexity: `O(n)`, where `n` is the length of the pushed vector.
- Space Complexity: `O(n)`, for `st`.

## Code
```cpp
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
```