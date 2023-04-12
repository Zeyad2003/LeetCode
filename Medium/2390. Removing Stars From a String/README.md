# [2390. Removing Stars From a String](https://leetcode.com/problems/removing-stars-from-a-string/)

## Solution
- Use a stack to store the characters in the string.
- When you meet a star, pop the top element of the stack.
- After the loop, the stack will contain the characters you want to return.
- Reverse the string and return it.

## Complexity
- Time Complexity: `O(n)`, where `n` is the length of the string.
- Space Complexity: `O(n)`, for `st`.

## Code
```cpp
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
```