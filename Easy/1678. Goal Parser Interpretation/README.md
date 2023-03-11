# [1678. Goal Parser Interpretation](https://leetcode.com/problems/goal-parser-interpretation/)

## Solution
- Loop through the string.
- If the current character is `G`, append `G`.
- If the current character is `(`, check the next character.
    - If the next character is `)`, append `o` and skip the next character.
    - If the next character is `a`, append `al` and skip the next 3 characters.
## Complexity
- Time Complexity: `O(n)`, where `n` is the length of the string.

- Space Complexity: `O(n)`, where `n` is the length of the string.
## Code
``` cpp
class Solution {
public:
    string interpret(string command) {
        int n = (int) command.size();
        string ans;
        for(int i = 0; i < n; i++) {
            if(command[i] == 'G') { // add G
                ans.push_back('G');
            }
            else if(command[i] == '(' and command[i + 1] == ')') { // Add O
                ans.push_back('o');
                i++; // skip )
            } else { // Add al
                ans.push_back('a');
                ans.push_back('l');
                i += 3; // Skip al)
            }
        }
        return ans;
    }
};
```